### 说明文件

文件写入还有一点问题；

等有更加合适的方法在补充；

推荐问题网站：

stackoverflow: 这个网站的问题定位清晰，很容易找到问题的根源

CSDN：这个内容杂乱，慢慢大海定位问题难；不过C++社区还是值得逛；



### 
+ 问题1
	> in.eof() 最后多读一行怎么解决
	> 使用in.peek()!=EOF（尝试不能解决）
	```c++
	while (!in.eof() && in.peek() != EOF)
	{
		q = new SIMS;

		q->infile(in);
		count+=1;
		p->next = q;
		q->next = NULL;
		p = p->next;
		if (in.eof()) // 到达文件末尾则break
			break;
	}
	```
+ 问题2	
	>文件输入输出的控制
	ifstream 是从硬盘读取数据到内存区域
+ 问题3
	>字符指针的读取会错误
	>添加学生的时候指针是创建一个学生指针，之后将原有的尾部连接到这个学生，之后将新创建的指针置为空
+ 问题4
	>将字符串转为字符指针的方法
	
	```c++
		string buffer;
	in >> stu_id; in >> buffer;
	stu_name = new char[strlen(buffer.c_str()) + 1];
	strcpy(stu_name, buffer.c_str());
	in >> stu_gender;
	in >> stu_score;
	in >> rank;
	```
	
+ 问题5
	>写入文件的操作
	```c++
	fstream file;
			file.open("C:\\Users\\HP\\Desktop\\rec\\student.txt", std::ios::app);
			file << endl;
			file << id << "\t" << name << "\t\t" << gender << "\t" << score <<'\t'<<rak<<endl;
	```
+ 问题6
	>指针操作
+ 问题7
	>私有和保护对象的区别
	保护属性在继承类的时候可以直接使用，私有对象只能在本类内进行访问，类外就要使用函数获取
+ 问题8
	>追加写入的时候怎么另起一行进行追加
	std::ios::app
