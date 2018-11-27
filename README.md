# Improve on the Linear-Time Component-Labeling Algorithm (FastLCL)

Development Environment: Microsoft Windows 10, Microsoft Visual C++ 2017.

## 改進基於線性時間元件標籤演算法
## Improve on the Linear-Time Component-Labeling Algorithm

### 摘要
本文提出了一種新的高性能線性時間演算法，採用輪廓跟踪技術，這些輪廓採用二值化影像。該演算法的主要步驟是使用輪廓追踪技術來檢測每個元件的外部輪廓，並且還識別和標記每個元件的內部區域。標籤演算法在影像上一次完成。而且，在整個過程中不需要重新標記。本研究改進了張復等人的LCL算法。我們的演算法比LCL算法更快更好。對各種類型影像（字符，半色調圖片，照片，報紙等）的實驗表明，我們的方法優於使用同樣技術的方法。我們的算法不僅標記元件，而且能夠抽取出元件輪廓和輪廓點的順序，這對於許多應用都很有用，例如OCR（光學字符讀取器），視頻分析中的對象跟踪等。本文列出本研究的演算法與LCL做比較，以證明所提出的方法更快。
### 關鍵字：元件標籤演算法，輪廓追蹤，線性時間演算法，孤立點。

### Abstract
A new high-performance linear time algorithm is presented in this article using contour tracing technique and these contours is in binary images. The main step of this algorithm is to use a contour tracing technique to detect the external contour of each component, and also to identify and label the interior area of each component. Labeling is done in a single pass over the image. Moreover, no relabeling is required throughout the entire process. This study improves LCL algorithm by Fu Chang et al. And our algorithm is faster and better than LCL algorithm. Experimentation with various types of images (characters, halftone pictures, photographs, newspaper, etc.) shows that our method outperforms methods that use the equivalence technique. Our algorithm not only labels components, and it is able to extract component contours and sequential orders of contour points, which can be useful for many applications, such as OCR (Optical Character Reader), object tracking in video analysis, etc. A comparison with LCL algorithm is made, to demonstrate that the proposed method is faster.
### Keywords: Component-Labeling Algorithm, Contour Tracing, Linear-Time Algorithm, Isolated Point.

### YouTube


### Keywords or Tags
Image Processing, Component-Labeling Algorithm, Contour Tracing, Linear-Time Algorithm, Isolated Point, Visual C++ 2017. 

### GitHub
https://github.com/laitaiyu/ImageProcessing__FastLCL

## Authors
Lai Lin-Wen（賴琳紋），British Computer Society（英國電腦學會）
Lai Tai-Yu（賴岱佑），International Association of Computer Science and Information Technology（國際電腦科學與資訊科技協會）

### Blog
https://laitaiyu.blogspot.com/

## Example

The "X:\" means your path name.

X:\FastLCL.EXE Experiment_09.pbm
*****************************************************************************************
* Lai Lin-Wen, British Computer Society.                                                *
* Lai Tai-Yu, International Association of Computer Science and Information Technology. *
*=======================================================================================*
* Improve on the Linear-Time Component-Labeling Algorithm.                              *
* Published: 27th November 2018                                                         *
*****************************************************************************************
No. 1
Processing Time: 24.681077 milliseconds
CC# 21205.

No. 2
Processing Time: 24.014608 milliseconds
CC# 21205.

No. 3
Processing Time: 26.135693 milliseconds
CC# 21205.

No. 4
Processing Time: 27.186162 milliseconds
CC# 21205.

No. 5
Processing Time: 30.687988 milliseconds
CC# 21205.

No. 6
Processing Time: 23.506954 milliseconds
CC# 21205.

No. 7
Processing Time: 26.222212 milliseconds
CC# 21205.

No. 8
Processing Time: 25.791200 milliseconds
CC# 21205.

No. 9
Processing Time: 26.390508 milliseconds
CC# 21205.

No. 10
Processing Time: 33.280382 milliseconds
CC# 21205.

Total of The Processing Time: 267.896783
Average Processing Time: 26.789678
Press any key to continue . . .


X:\ccl.EXE Experiment_09.pbm
**************************************************************************************
* F. Chang, C. J. Chen, and C. J. Lu                                                 *
*====================================================================================*
* A Linear-Time Component-Labeling Algorithm Using Contour Tracing Technique.        *
* Computer Vision and Image Understanding, vol. 93, no. 2, Feb. 2004, pp. 206 - 220. *
**************************************************************************************
No. 1
Processing Time: 29.421816 milliseconds
CC# 21205.

No. 2
Processing Time: 31.627049 milliseconds
CC# 21205.

No. 3
Processing Time: 30.083544 milliseconds
CC# 21205.

No. 4
Processing Time: 28.750211 milliseconds
CC# 21205.

No. 5
Processing Time: 31.416876 milliseconds
CC# 21205.

No. 6
Processing Time: 30.226951 milliseconds
CC# 21205.

No. 7
Processing Time: 30.861025 milliseconds
CC# 21205.

No. 8
Processing Time: 30.237223 milliseconds
CC# 21205.

No. 9
Processing Time: 30.907247 milliseconds
CC# 21205.

No. 10
Processing Time: 31.006408 milliseconds
CC# 21205.

Total of The Processing Time: 304.538349
Average Processing Time: 30.453835
Press any key to continue . . .

