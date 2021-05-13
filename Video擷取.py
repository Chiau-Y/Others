import cv2
import matplotlib.pyplot as plt

# Reference : https://reurl.cc/nn9ayv

def get_images_from_video(video_name, time_F):
    video_images = []
    vc = cv2.VideoCapture(video_name)    # 開啟視訊檔案
    # 設定影像的尺寸大小
    vc.set(cv2.CAP_PROP_FRAME_WIDTH, 1468)
    vc.set(cv2.CAP_PROP_FRAME_HEIGHT, 1044)
    c = 1
    
    if vc.isOpened():    # 判斷是否開啟影片
        rval, video_frame = vc.read()    # rval為有沒有讀到影片
    else:
        rval = False

    while rval:    # 擷取視頻至結束
        rval, video_frame = vc.read()
        
        if(c % time_F == 0):    # 每隔幾幀進行擷取
            video_images.append(video_frame)     
        c = c + 1
    vc.release()    # 釋放攝影機
    
    return video_images

time_F = 25    # time_F越小，取樣張數越多
video_name = "C:/Users/ICLab_Brian/Desktop/test.mp4"    # 影片名稱
video_images = get_images_from_video(video_name, time_F)    # 讀取影片並轉成圖片

# for i in range(0, len(video_images)):    # 顯示出所有擷取之圖片
for i in range(0, 20):    # 顯示出特地幾張圖片
    plt.figure(i)
    plt.imshow(video_images[i][...,::-1])    # 顯示圖片
    plt.axis('off')    # 不顯示座標軸
    
# # 儲存圖片
# cv2.imwrite("C:/Users/ICLab_Brian/Desktop/test.png", video_images[25])