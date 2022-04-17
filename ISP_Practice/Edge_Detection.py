import cv2
import matplotlib.pyplot as plt

image = cv2.imread('D:/CHIAUYAUN/GitHub/test.jpg')
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
blurred = cv2.GaussianBlur(gray, (5, 5), 0)
sobel_x = cv2.Sobel(blurred,-1,1,0)
sobel_y = cv2.Sobel(blurred,-1,0,1)
canny = cv2.Canny(blurred, 30, 150)
laplacian = cv2.Laplacian(blurred, cv2.CV_16S)

plt.figure(0)
plt.imshow(image[:,:,[2,1,0]]) # 顯示圖片
plt.axis('off') 
plt.figure(1)   
plt.imshow(gray, cmap='Greys_r') 
plt.axis('off') 
plt.figure(2)   
plt.imshow(sobel_x, cmap='Greys_r') 
plt.axis('off') 
plt.figure(3)   
plt.imshow(sobel_y, cmap='Greys_r') 
plt.axis('off') 

# 對噪聲具有平滑作用，抗噪聲能力強，計算量較大，但定位精度不高
# 得到的邊緣比較粗，適用於精度要求不高的場合
plt.figure(4)   
plt.imshow((sobel_x + sobel_y), cmap='Greys_r') 
plt.axis('off') 

# 使用兩種不同的閾值分別檢測強邊緣和弱邊緣，並且當弱邊緣和強邊緣相連時，纔將弱邊緣包含在輸出圖像中
# 保留細節，抗噪能力強
plt.figure(5)   
plt.imshow(canny, cmap='Greys_r')   
plt.axis('off') 

# 容易受噪聲影響，不能檢測邊緣的方向，一般不直接用於檢測邊緣，而是判斷明暗變化
plt.figure(6)   
plt.imshow(cv2.convertScaleAbs(laplacian), cmap='Greys_r')   # 保留細節
plt.axis('off') 