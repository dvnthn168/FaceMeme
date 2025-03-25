"# FaceMeme" 
Cách hoạt động

Đọc ảnh: Đọc ảnh đầu vào và ảnh meme (icon) có kênh alpha.

Phát hiện gương mặt: Phát hiện gương mặt bằng mô hình Haar Cascade.

Chèn Meme: Chèn meme đã thay đổi kích thước lên mỗi gương mặt, giữ nguyên độ trong suốt.

Lưu ảnh kết quả: Xuất ảnh kết quả ra output_image/output.png.

Các tệp đầu vào

Đảm bảo các tệp sau có trong thư mục input_image/:

input.jpg - Ảnh đầu vào để phát hiện gương mặt.

icon.png - Ảnh meme có kênh alpha (RGBA).

haarcascade_frontalface_default.xml - Mô hình phát hiện gương mặt được huấn luyện trước từ OpenCV.

Đầu ra

Ảnh sau khi chèn meme sẽ được lưu tại:

output_image/output.png

Tuỳ chỉnh

Thay đổi đường dẫn: Chỉnh sửa biến imagePath, memePath, và đường dẫn đầu ra trong main.cpp.

Điều chỉnh thông số phát hiện: Tinh chỉnh các tham số của hàm detectMultiScale() để cải thiện độ chính xác.
