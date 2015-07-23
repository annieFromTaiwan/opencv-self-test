import cv2 
import sys 

if len(sys.argv) == 2:
    video_path = sys.argv[1]
else:
    video_path = "/nas/android_movies/wanfi_2015Feb/shot_from_wanfi/B_WeiLun_D024/DMOV_0006.mp4"

cap = cv2.VideoCapture(video_path)
if not cap:
    print "can't open video:", video_path
    sys.exit(0)

print "fps:", cap.get(cv2.cv.CV_CAP_PROP_FPS)
sys.exit(0)

while True:
    ret, frame = cap.read()

    if frame is None:
        print "no frame"
        break

    cv2.imshow('video', frame)
    if cv2.waitKey(1) & 0xff == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()


