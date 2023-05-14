Chương trình được viết trên IDE: Visual Studio 2019
Trong chương trình có sử dụng thuật toán:
+ Sủi bọt trong mã số nhập: thực hiện sắp xếp dãy số bằng cách lặp lại công việc đổi chỗ 2 số 
liên tiếp nhau nếu chúng đứng sai thứ tự(số sau bé hơn số trước với trường hợp sắp xếp tăng dần)
cho đến khi dãy số được sắp xếp.


+ Selection sort trong mã số cá nhân: Sắp xếp mảng bằng cách đi tìm phần tử có giá trị nhỏ nhất(giả sử với sắp xếp mảng tăng dần) trong đoạn đoạn chưa được 
sắp xếp và đổi cho phần tử nhỏ nhất đó với phần tử ở đầu đoạn chưa được sắp xếp(không phải đầu 
mảng). Thuật toán sẽ chia mảng làm 2 mảng con
	Một mảng con đã được sắp xếp
	Một mảng con chưa được sắp xếp
Tại mỗi vòng lặp của thuật toán, phần tử nhỏ nhất ở mảng con chưa được sắp xếp sẽ được di 
chuyển về đoạn đã sắp xếp.