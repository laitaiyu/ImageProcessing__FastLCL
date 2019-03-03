# Improve on the Linear-Time Component-Labeling Algorithm (FastLCL)
# 改進基於線性時間元件標籤演算法 <font size=10pt>(Traditional Chinese)</font>

## Abstract
A new high-performance linear time algorithm is presented in this article using contour tracing technique and these contours is in binary images. The main step of this algorithm is to use a contour tracing technique to detect the external contour of each component, and also to identify and label the interior area of each component. Labeling is done in a single pass over the image. Moreover, no relabeling is required throughout the entire process. This study improves LCL algorithm by Fu Chang et al. And our algorithm is faster and better than LCL algorithm. Experimentation with various types of images (characters, halftone pictures, photographs, newspaper, etc.) shows that our method outperforms methods that use the equivalence technique. Our algorithm not only labels components, and it is able to extract component contours and sequential orders of contour points, which can be useful for many applications, such as OCR (Optical Character Reader), object tracking in video analysis, etc. A comparison with LCL algorithm is made, to demonstrate that the proposed method is faster.
### Keywords: Component-Labeling Algorithm, Contour Tracing, Linear-Time Algorithm, Isolated Point.

## 摘要 <font size=9pt>(Traditional Chinese)</font>
本文提出了一種新的高性能線性時間演算法，採用輪廓跟踪技術，這些輪廓採用二值化影像。該演算法的主要步驟是使用輪廓追踪技術來檢測每個元件的外部輪廓，並且還識別和標記每個元件的內部區域。標籤演算法在影像上一次完成。而且，在整個過程中不需要重新標記。本研究改進了張復等人的LCL算法。我們的演算法比LCL算法更快更好。對各種類型影像（字符，半色調圖片，照片，報紙等）的實驗表明，我們的方法優於使用同樣技術的方法。我們的算法不僅標記元件，而且能夠抽取出元件輪廓和輪廓點的順序，這對於許多應用都很有用，例如OCR（光學字符讀取器），視頻分析中的對象跟踪等。本文列出本研究的演算法與LCL做比較，以證明所提出的方法更快。
### 關鍵字：元件標籤演算法，輪廓追蹤，線性時間演算法，孤立點。<font size=8pt>(Traditional Chinese)</font>

### Related Site

<table border="1" width="100%">
	<tr>
		<td><b>Site</b></td>
		<td><b>Hyperlink<b></td>
	</tr>
	<tr>
		<td>YouTube</td>
		<td></td>
	</tr>
	<tr>
		<td>GitHub</td>
		<td><a href="https://github.com/laitaiyu/ImageProcessing__FastLCL">https://github.com/laitaiyu/ImageProcessing__FastLCL</a></td>
	</tr>
	<tr>
		<td>F. Chang, C-J. Chen, and C-J. Lu, "A Linear-Time Component-Labeling Algorithm Using Contour Tracing Technique," Computer Vision and Image Understanding, volume 93, number 2, pages 206-220, January 2004</td>
		<td><a href="https://www.iis.sinica.edu.tw/papers/fchang/1362-F.pdf" target="_blank">https://www.iis.sinica.edu.tw/papers/fchang/1362-F.pdf</a></td>
	</tr>
</table>

### Tags
* Image Processing, Component-Labeling Algorithm, Contour Tracing, Linear-Time Algorithm, Isolated Point, Visual C++ 2017. 

### Authors
1. Lai Lin-Wen（賴琳紋），British Computer Society（英國電腦學會）
2. Lai Tai-Yu（賴岱佑），International Association of Computer Science and Information Technology（國際電腦科學與資訊科技協會），Email: <a href="mailto:Mr.LaiTaiyu@gmail.com">Mr.LaiTaiyu@gmail.com</a>，Blog: https://laitaiyu.blogspot.com/

### Development Environment 

<table border="1" width="100%">
	<tr>
		<td><b>Item</b></td>
		<td><b>Description<b></td>
	</tr>
	<tr>
		<td>Operating System（作業系統）</td>
		<td>Microsoft Windows 10 Pro Build 1809</td>
	</tr>
	<tr>
		<td>Integrated Development Environment（整合式開發環境）</td>
		<td>Microsoft Visual Studio 2017</td>
	</tr>
	<tr>
		<td>Programming Language</td>
		<td>Standard C</td>
	</tr>
</table>

### Version History

<table border="1" width="100%">
	<tr>
		<td><b>Version</b></td>
		<td><b>Description<b></td>
	</tr>
	<tr>
		<td>FastLCL v1.1.2019.0303<br/>
			<font size=8pt><i>Published: 3rd March 2019</i></font>
		</td>
		<td>Title: Improve on the Linear-Time Component-Labeling Algorithm.<br/>
			Conference: International Conference on Information Technologies and Practices in 2019<br/>
			Place: School of Information Technology, Ming Chuan University, Taiwan(R.O.C.)<br/>
			Conference Date: 15th March, 2019
		</td>
	</tr>
	<tr>
		<td>FastLCL v1.0.2018.1127<br/>
			<font size=8pt><i>Published: 27th November 2018</i></font>
		</td>
		<td>
		</td>
	</tr>
</table>

### Measurement

<table border="1" width="100%">
	<tr>
		<td rowspan="2"><b>Sample (PBM Format)</b></td>
		<td rowspan="2" align="center"><b><a href="https://www.iis.sinica.edu.tw/papers/fchang/1362-F.pdf" target="_blank">LCL</a></b><br/>
			<font size="8pt">milliseconds</font>
		</td>
		<td colspan="2" align="center"><b>FastLCL</b><br/>
			<font size="8pt">milliseconds</font>
		</td>
	</tr>
	<tr>
		<td align="center"><b>v1.0.2018.1127</b></td>
		<td align="center"><b>v1.1.2019.0303</b></td>
	</tr>
	<tr>
		<td>Experiment_01__Eulr</td>
		<td align="right"><font color="red">0.009660 ms</font></td>
		<td align="right">0.006440 ms</td>
		<td align="right"><font color="green">0.003740 ms</font></td>
	</tr>
	<tr>
		<td>Experiment_02__A_flame_object</td>
		<td align="right">0.220040 ms</td>
		<td align="right"><font color="red">0.260780 ms</font></td>
		<td align="right"><font color="green">0.217610 ms</font></td>
	</tr>
	<tr>
		<td>Experiment_03__A_texture</td>
		<td align="right">0.703390 ms</td>
		<td align="right"><font color="red">0.758140 ms<font></td>
		<td align="right"><font color="green">0.595890 ms</font></td>
	</tr>
	<tr>
		<td>Experiment_04__Repeat_a_sentence</td>
		<td align="right"><font color="red">1.563260 ms</font></td>
		<td align="right">1.425820 ms</td>
		<td align="right"><font color="green">1.339690 ms</font></td>
	</tr>
	<tr>
		<td>Experiment_05__A_newspaper_headline</td>
		<td align="right"><font color="red">4.716800 ms</font></td>
		<td align="right">4.402130 ms</td>
		<td align="right"><font color="green">4.192860 ms</font></td>
	</tr>
	<tr>
		<td>Experiment_06__A_legacy_newspaper</td>
		<td align="right"><font color="red">20.229020 ms</font></td>
		<td align="right">17.964300 ms</td>
		<td align="right"><font color="green">17.541440 ms</font></td>
	</tr>
	<tr>
		<td>Experiment_07__A_halftone_picture</td>
		<td align="right"><font color="red">38.299290 ms</font></td>
		<td align="right">31.355320 ms</td>
		<td align="right"><font color="green">31.066370 ms</font></td>
	</tr>
	<tr>
		<td>Experiment_08__A_Chinese_book’s_content</td>
		<td align="right"><font color="red">4.054470 ms</font></td>
		<td align="right">3.915350 ms</td>
		<td align="right"><font color="green">3.494280 ms</font></td>
	</tr>
	<tr>
		<td>Experiment_09__A_photograph</td>
		<td align="right"><font color="red">17.555960 ms</font></td>
		<td align="right">15.463360 ms</td>
		<td align="right"><font color="green">14.970010 ms</font></td>
	</tr>
	<tr>
		<td>Experiment_10__A_magazine_content</td>
		<td align="right"><font color="red">8.704330 ms</font></td>
		<td align="right">8.441100 ms</td>
		<td align="right"><font color="green">7.678110 ms</font></td>
	</tr>
	<tr>
		<td>Experiment_11__ISO Chart</td>
		<td align="right"><font color="red">5.410370 ms</font></td>
		<td align="right">4.955610 ms</td>
		<td align="right"><font color="green">4.696110 ms</font></td>
	</tr>
</table>


### Instruction Example

* The "X:\\" means your path name.
* "LCL.exe" is the <a href="https://www.iis.sinica.edu.tw/papers/fchang/1362-F.pdf" target="_blank">Linear-Time Component-Labeling Algorithm</a> by <a href="https://www.iis.sinica.edu.tw/pages/fchang/publications_en.html" target="_blank">F. Chang</a>, et al.
* "LCL.exe [<font color="blue">Parameter</font>]", the <font color="blue">Parameter</font> is a file name of the PBM format.
* "FastLCL.exe" is this study by Lai Lin-Wen and <a href="https://laitaiyu.blogspot.com" target="_blank">Lai Tai-Yu</a>. 
* "FastLCL.exe [<font color="blue">Parameter</font>]", the <font color="blue">Parameter</font> is a file name of the PBM format.

<pre>
<table border="2" width="100%" style="background-color:black; color:white;">
	<tr>
		<td>
X:\FastLCL.EXE Experiment_09.pbm

******************************************************************************************
* Authors:                                                                               *
* Lai Lin-Wen, British Computer Society.                                                 *
* Lai Tai-Yu, International Association of Computer Science and Information Technology.  *
*========================================================================================*
* Title: Improve on the Linear-Time Component-Labeling Algorithm.                        *
* Conference: International Conference on Information Technologies and Practices in 2019 *
* Place: School of Information Technology, Ming Chuan University, Taiwan(R.O.C.)         *
* Conference Date: 15th March, 2019                                                      *
*========================================================================================*
* FastLCL v1.1.2019.0303                                                                 *
* Published: 3rd March 2019                                                              *
******************************************************************************************
No. 1
Processing Time: 15.084700 milliseconds
CC# 21205.

No. 2
Processing Time: 14.919600 milliseconds
CC# 21205.

No. 3
Processing Time: 15.071000 milliseconds
CC# 21205.

No. 4
Processing Time: 14.977200 milliseconds
CC# 21205.

No. 5
Processing Time: 14.852200 milliseconds
CC# 21205.

No. 6
Processing Time: 14.971300 milliseconds
CC# 21205.

No. 7
Processing Time: 14.868000 milliseconds
CC# 21205.

No. 8
Processing Time: 14.881200 milliseconds
CC# 21205.

No. 9
Processing Time: 15.157600 milliseconds
CC# 21205.

No. 10
Processing Time: 14.854700 milliseconds
CC# 21205.

Total of The Processing Time: 149.637500 milliseconds
Average Processing Time: 14.963750 milliseconds
Press any key to continue . . .
		</td>
	</tr>
</table>
</pre>
<hr>

<pre>
<table border="2" width="100%" style="background-color:black; color:white;">
	<tr>
		<td>
X:\ccl.EXE Experiment_09.pbm

**************************************************************************************
* F. Chang, C. J. Chen, and C. J. Lu                                                 *
*====================================================================================*
* A Linear-Time Component-Labeling Algorithm Using Contour Tracing Technique.        *
* Computer Vision and Image Understanding, vol. 93, no. 2, Feb. 2004, pp. 206 - 220. *
**************************************************************************************
No. 1
Processing Time: 16.985400 milliseconds
CC# 21205.

No. 2
Processing Time: 16.932000 milliseconds
CC# 21205.

No. 3
Processing Time: 16.945800 milliseconds
CC# 21205.

No. 4
Processing Time: 16.908500 milliseconds
CC# 21205.

No. 5
Processing Time: 16.958100 milliseconds
CC# 21205.

No. 6
Processing Time: 16.980400 milliseconds
CC# 21205.

No. 7
Processing Time: 22.265200 milliseconds
CC# 21205.

No. 8
Processing Time: 16.948200 milliseconds
CC# 21205.

No. 9
Processing Time: 17.476400 milliseconds
CC# 21205.

No. 10
Processing Time: 17.084900 milliseconds
CC# 21205.

Total of The Processing Time: 175.484900 milliseconds
Average Processing Time: 17.548490 milliseconds
Press any key to continue . . .
		</td>
	</tr>
</table>
</pre>

***
<table width="100%" style="background-color:#EEEEEE;">
	<tr>
		<td align="center">Copyright &copy; 2019 Lai Lin-Wen and Lai Tai-Yu.</td>
	</tr>
	<tr>
		<td align="right"><font size="8pt"><i>Last Update: 3rd March, 2019</i></font></td>
	</tr>
</table>