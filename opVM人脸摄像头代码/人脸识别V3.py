# Face recognition with LBP descriptors.
# See Timo Ahonen's "Face Recognition with Local Binary Patterns".
#
# Before running the example:
# 1) Download the AT&T faces database http://www.cl.cam.ac.uk/Research/DTG/attarchive/pub/data/att_faces.zip
# 2) Exract and copy the orl_faces directory to the SD card root.


import sensor, time, image, pyb

sensor.reset() # Initialize the camera sensor.
sensor.set_pixformat(sensor.GRAYSCALE) # or sensor.GRAYSCALE
sensor.set_framesize(sensor.B128X128) # or sensor.QQVGA (or others)
sensor.set_windowing((92,112))
sensor.skip_frames(10) # Let new settings take affect.
sensor.skip_frames(time = 500) #等待0.5s
from pyb import Pin

LED1 = Pin('P8', Pin.OUT_PP) ##正常
LED1.high() #g


LED2 = Pin('P9', Pin.OUT_PP)#报警
LED2.high() #g


#key.low()#d
#SUB = "s1"
NUM_SUBJECTS = 1 #图像库中不同人数，一共6人
NUM_SUBJECTS_IMGS = 30 #每人有20张样本图片

# 拍摄当前人脸。
img = sensor.snapshot()
#img = image.Image("singtown/%s/1.pgm"%(SUB))
d0 = img.find_lbp((0, 0, img.width(), img.height()))
#d0为当前人脸的lbp特征
img = None
pmin = 999999
num=0

clock = time.clock()
pin1 = Pin('P1', Pin.IN, Pin.PULL_UP)   ##将P1口作为阈值控制口 OUT_PP PULL_NONE



def min(pmin, a, s):
    global num
    if a<pmin:
        pmin=a
        num=s
    return pmin

while(True):

    clock.tick()
    img = sensor.snapshot()
    key0 = pin1.value()      ##按键控制
    if key0 ==1:
        print("key0 ok!")
        import sensor, time, image, pyb
        sensor.reset() # Initialize the camera sensor.
        sensor.set_pixformat(sensor.GRAYSCALE) # or sensor.GRAYSCALE
        sensor.set_framesize(sensor.B128X128) # or sensor.QQVGA (or others)
        sensor.set_windowing((92,112))
        sensor.skip_frames(10) # Let new settings take affect.
        sensor.skip_frames(time = 500) #等待0.5s
          # 拍摄当前人脸。
        img = sensor.snapshot()
        #img = image.Image("singtown/%s/1.pgm"%(SUB))
        d0 = img.find_lbp((0, 0, img.width(), img.height()))
        #d0为当前人脸的lbp特征
        img = None
        pmin = 999999
        num=0
        for s in range(1, NUM_SUBJECTS+1):
            dist = 0
            for i in range(2, NUM_SUBJECTS_IMGS+1):
                img = image.Image("singtown/s%d/%d.pgm"%(s, i))
                d1 = img.find_lbp((0, 0, img.width(), img.height()))
                #d1为第s文件夹中的第i张图片的lbp特征
                dist += image.match_descriptor(d0, d1)#计算d0 d1即样本图像与被检测人脸的特征差异度。
            print("Average dist for subject %d: %d"%(s, dist/NUM_SUBJECTS_IMGS))
            pmin = min(pmin, dist/NUM_SUBJECTS_IMGS, s)#特征差异度越小，被检测人脸与此样本更相似更匹配。
            print(pmin)

        print(num) # num为当前最匹配的人的编号。
        if pmin>8000:
                     LED1.off()
                     LED2.on()#关闭
                     print("发现陌生人！") # num为当前最匹配的人的编号。

        else:
                LED1.on()#关闭
                LED2.off();#打开



