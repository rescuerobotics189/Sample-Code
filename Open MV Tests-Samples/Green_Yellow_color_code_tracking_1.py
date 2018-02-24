# A color code is a blob composed of 1 color.
import sensor, image, time

from machine import Pin, Signal #for LED Lights

# Color Tracking Thresholds (L Min, L Max, A Min, A Max, B Min, B Max)
# The below threshold tracks green/yellow objects.
thresholds = [(50, 200, -64, -8, -32, 32)]

sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
sensor.skip_frames(150)
sensor.set_auto_gain(False) # must be turned off for color tracking
sensor.set_auto_whitebal(False) # must be turned off for color tracking
clock = time.clock()

#Pin Setups to LEDs
p0 = Pin('P0', Pin.OUT_PP)
p1 = Pin('P1', Pin.OUT_PP)
p2 = Pin('P2', Pin.OUT_PP)
p3 = Pin('P3', Pin.OUT_PP)
top_led = Signal(p0, invert=False)
bot_led = Signal(p1, invert=False)
left_led = Signal(p2, invert=False)
right_led = Signal(p3, invert=False)

# Only blobs that with more pixels than "pixel_threshold" and more area than "area_threshold" are
# returned by "find_blobs" below. Change "pixels_threshold" and "area_threshold" if you change the
# camera resolution. "merge=True" must be set to merge overlapping color blobs for color codes.
while(True):
    clock.tick()
    img = sensor.snapshot()
    for blob in img.find_blobs(thresholds, pixels_threshold=200, area_threshold=200, merge=True):
        img.draw_rectangle(blob.rect())
        img.draw_cross(blob.cx(), blob.cy())
        img.draw_string(blob.x() + 1, blob.y() + 1, "Yellow Ball")
       # Area = blob.area()
        #print("Area of blob is:", Area)
        print ("x=",blob.x(),"y=",blob.y())
    if   (blob.x())<=160: left_led.on()
    elif  (blob.x())>=160: left_led.off()
    if   (blob.y())<=120: top_led.on()
    elif  (blob.y())>=120: top_led.off()
    if   (blob.x())>=160: right_led.on()
    elif  (blob.x())<=160: right_led.off()
    if   (blob.y())>=120: bot_led.on()
    elif  (blob.y())<=120: bot_led.off()


