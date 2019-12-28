#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<ctime>

using namespace std;

class SLLNode {
public:
	SLLNode() {
		next = 0;
	}
	SLLNode(int el, string name, SLLNode *ptr = 0) {
		date = el; movie=name; next = ptr;
	}
	int date;
	string movie;
	SLLNode *next;
};

class SLList {
public:
	SLList() {
		head = tail = 0;
	}
	int isEmpty() {
		return head == 0;
	}

	
	void addMovie(int,string);
	void deleteMovie(string);
	void sortDate();
	void ChangeInfo(string);
	void searchMovie();
	bool IsInTheList(string,int);

	int NumberOfMovie() {
		int len=0;
		for (SLLNode *tmp = head; tmp != 0; tmp = tmp->next) {
			len++;
		}
		return len;
		}

	void printAll() const;
	void MoviefileIn();
	void MoviefileOut(int);

	int quizQuestion(int,int,int);
	SLLNode *Node(int);

private:
	SLLNode *head, *tail;
};

int trueInt() {//check if input is integer or not
	int x;
	while(!(cin>>x)) {
		cin.clear();
		cin.ignore();
	}
	return x;
}

SLLNode *SLList::Node(int N) {
	SLLNode *tmp=head;
	for(int i=0;i<N;i++)
		tmp=tmp->next;
	return tmp;
}

void SLList::addMovie(int date,string name) {

	int flag=1,option,count=0;
	SLLNode *tmp;
	for(tmp=head;tmp!=0;tmp=tmp->next) {
		if(IsInTheList(name,count) && name.length()==tmp->movie.length()) {
			cout<<count+1<<")"<<tmp->date<<"	"<<tmp->movie<<endl;
			cout<<"This movie is in the list.Are you sure to add it"<<endl;
			cout<<"1)yes\n2)No"<<endl;
			option=trueInt();
			flag=0;
			if(option==1)
				flag=1;
		}
		count++;
	}

	if(flag) {
		if (tail != 0) {  
			tail->next = new SLLNode(date,name);
			tail = tail->next;
		}
		else head = tail = new SLLNode(date,name);
	}
}
void SLList::sortDate() {
	SLLNode *tmp1,*tmp2,temp;
	int date;
	string movie;
	for(tmp1=head;tmp1!=0;tmp1=tmp1->next) {
		for(tmp2=tmp1;tmp2!=0;tmp2=tmp2->next) {
			if((tmp1->date)>(tmp2->date)) {
				date=tmp2->date;
				movie=tmp2->movie;
				tmp2->date=tmp1->date;				
				tmp2->movie=tmp1->movie;
				tmp1->date=date;
				tmp1->movie=movie;
			}
		}	
	}
}
void SLList::printAll() const {
	int i=1;
	for (SLLNode *tmp = head; tmp != 0; tmp = tmp->next) {
		cout <<i<<")"<<tmp->date<<tmp->movie<<endl;
		i++;
	}
	std::cout << std::endl;
}
void SLList::deleteMovie(string name) {
	SLLNode *temp=head;
	int options,count=0,year,count2;
	int flag=0;

	for(temp=head;temp!=0;temp=temp->next) {
		if(IsInTheList(name,count)) {
			cout<<count+1<<")"<<temp->date<<"	"<<temp->movie<<endl;
			flag++;
			year=temp->date;
			count2=count+1;
			temp=Node(count2-1);
		}
		count++;
	}
	if(flag>1) {
		cout<<"Enter Movie Date:";
		year=trueInt();
		cout<<"Enter movie line"<<endl;
		count2=trueInt();

		if(count2>NumberOfMovie()) { cout<<"Movie Not found!!"<<endl; return; }

		temp=Node(count2-1);
		cout<<count2<<")"<<temp->date<<"	"<<temp->movie<<"\n"<<endl;
	}
	else if(flag==1)
		temp=Node(count2-1);
	else if(flag==0) {
		cout<<"Movie Not found!!"<<endl;
		return;
	}
	cout<<"Are you sure you want to delete?\n1)yes\n2)no"<<endl;
	options=trueInt();

	if(head!=0 && options==1) {
		if(head==tail && head==temp) {
			delete head;
			cout<<"Movie Deleted!!"<<endl;                      
			head = tail = 0;
		}
		else if(head==temp) {
			head=head->next;
			delete temp;
			cout<<"Movie Deleted!!"<<endl;
		}
		else {
			SLLNode *pretemp=Node(count2-2);
			pretemp->next=temp->next;
			delete temp;
			cout<<"Movie Deleted!!"<<endl;
		}
	}
	else
		return;

}
void SLList::ChangeInfo(string name) {
	SLLNode *temp=head;
	int options, newDate,count=0,year,count2;
	string newName;
	int flag=0;
	string space=" ";

	for(temp=head;temp!=0;temp=temp->next) {
		if(IsInTheList(name,count)) {
			cout<<count+1<<")"<<temp->date<<"	"<<temp->movie<<endl;
			flag++;
			year=temp->date;
			count2=count+1;
			temp=Node(count2-1);
		}
		count++;
	}
	if(flag>1) {
		cout<<"Enter Movie Date:";
		year=trueInt();
		cout<<"Enter movie line"<<endl;
		count2=trueInt();

		if(count2>NumberOfMovie()) { cout<<"Movie Not found!!"<<endl; return; }

		temp=Node(count2-1);
		cout<<count2<<")"<<temp->date<<"	"<<temp->movie<<"\n"<<endl;
	}
	if(flag==1)
		temp=Node(count2-1);

	if(IsInTheList(name,count2-1) && (year==temp->date)) {
			cout<<"1)Movie Name\n2)Movie Date\n3)Both\n4)Exit"<<endl;
			options=trueInt();
			if(options==1) {
				cout<<"Enter Movie Name:";
				getline(cin,newName);
				getline(cin,newName);
				newName=space+newName;
				temp->movie=newName;
			}
			else if(options==2) {
				cout<<"Enter Movie Date:";
				newDate=trueInt();
				temp->date=newDate;
			}
			else if(options==3) {
				cout<<"Enter Movie Name:";
				getline(cin,newName);
				getline(cin,newName);
				newName=space+newName;
				cout<<"Enter Movie Date:";
				newDate=trueInt();
				temp->movie=newName;
				temp->date=newDate;
			}
			else if(options==4) {
				return;
			}
			else {
				cout<<"Wrong comment"<<endl;
			}
	}
	else
		cout<<"Movie Not found!!"<<endl;
}

bool SLList::IsInTheList(string name,int count) {
	int j=0;
	int len=0;
	SLLNode *tmp=Node(count);
	for(j=0;j<(tmp->movie.length());j++) {
		if(tmp->movie[j]==name[len] || tmp->movie[j]==(name[len]+32) || tmp->movie[j]==(name[len]-32)) {	
			len++;
			if(name.length()==len)
				return true;
		}
		else
			len=0;
		

	}
	return false;

}

void SLList::searchMovie() {

	int year,style,count,flag=1;
	string name;
	SLLNode *tmp;
	string space=" ";
	
	cout<<"1)Search by date\n2)Search by name\n3)others to exit"<<endl;
	style=trueInt();
	if(style==1) {
		cout<<"Enter Date:";
		year=trueInt();
		cout<<"List of all film date "<<year<<endl;
		for(tmp=head;tmp!=0;tmp=tmp->next) {
			if(tmp->date==year) {
				cout<<count<<")"<<tmp->movie<<endl;
				flag=0;
			}
			count++;
		}
	}
	else if(style==2) {
		cout<<"Enter Movie Name:"<<endl;
		getline(cin,name);
		getline(cin,name);
		name=space+name;
		int size=NumberOfMovie();
		for(count=0;count<size;count++)
			if(IsInTheList(name,count)) {
				tmp=Node(count);
				cout<<count+1<<")"<<tmp->date<<tmp->movie<<endl;
				flag=0;
			}
		

	}
	else {
		cout<<"Wrong comment"<<endl;
	}
	if(flag)
		cout<<"Film Not found!!!"<<endl;
}

void SLList::MoviefileIn() {

	ifstream file("MovieFile.txt");
	SLLNode *tmp;
	int date,len;
	string name;
	if(file.is_open()) {
		file>>len;
		for(int i=0;i<len;i++) {
			file>>date;
			getline(file,name);
			addMovie(date,name);
		}
		file.close();
	}
	else {
		cout<<"No File"<<endl;
		
	}
}

void SLList::MoviefileOut(int len) {

	ofstream file("MovieFile.txt");
	SLLNode *tmp;
	file<<len<<"\n";
	for(tmp=head;tmp!=0;tmp=tmp->next) {
		file<<tmp->date<<"";
		file<<tmp->movie<<"\n";
	}
	file.close();
	cout<<"File is Successfully Terminated"<<endl;
}


int SLList::quizQuestion(int len,int ran,int style) {
	SLLNode *q1,*q2,*q3,*q4,*tr;
	string answer,ans;
	int num;
	srand(ran);
	
	q1=Node(rand()%len);
	q2=Node(rand()%len);
	q3=Node(rand()%len);
	q4=Node(rand()%len);

	while(q1->date==q2->date || q1->date==q3->date || q1->date==q4->date || q2->date==q3->date || q2->date==q4->date || q3->date==q4->date) {
		q1=Node(rand()%len);
		q2=Node(rand()%len);
		q3=Node(rand()%len);
		q4=Node(rand()%len);
	}

	num=1+(rand()%4);
	if     (num==1)	{tr=q1; answer="a";}
	else if(num==2) {tr=q2; answer="b";}
	else if(num==3) {tr=q3; answer="c";}
	else if(num==4) {tr=q4; answer="d";}

	if(style==1) {
		cout<<"Which year was the movie "<<tr->movie<<" released?"<<endl;
		cout<<"a)"<<q1->date<<endl;
		cout<<"b)"<<q2->date<<endl;
		cout<<"c)"<<q3->date<<endl;
		cout<<"d)"<<q4->date<<endl;
	}
	else if(style==2) {
		cout<<"Which year the following movies was released in "<<tr->date<<endl;
		cout<<"a)"<<q1->movie<<endl;
		cout<<"b)"<<q2->movie<<endl;
		cout<<"c)"<<q3->movie<<endl;
		cout<<"d)"<<q4->movie<<endl;

	}
	cin>>ans;
	while(ans!="a" || ans!="b" || ans!="c" || ans!="d")	{
		if(ans==answer) {cout<<"Correct"<<endl; return 10;}
		else if ((ans=="a" || ans=="b" || ans=="c" || ans=="d") && ans!=answer) {
			cout<<"False	True answer is:"<<answer<<endl; return 0;
		}
		else if(ans!="a" || ans!="b" || ans!="c" || ans!="d") {
			cout<<"push correct button"<<endl;
			cin>>ans;
		}
		
	}

}

int main() {

	int key,command=1,len;
	int date;
	int newDate;
	string newName;
	SLList Movies;

	int numOfQuestion=0;
	int questionStyle;
	int grade=0;
	string space=" ";

	Movies.MoviefileIn();

	cout<<"Welcome"<<endl;
	cout<<"Press 1 to administration"<<endl;
	cout<<"press 2 to quiz"<<endl;
	cout<<"press others to exit"<<endl;
	key=trueInt();
	cout<<endl;
	if(key==1) {
		while(command!=6) {

			cout<<"\nEnter New Command:\n1)Add Movie\n2)Delete Movie\n";
			cout<<"3)Change Info\n4)Search Movie\n5)Print all Movie\n6)Exit\n";
			command=trueInt();
			len=Movies.NumberOfMovie();
			
			if(command==1) {
				cout<<"Enter Date:";
				date=trueInt();
				cout<<endl;
				cout<<"Enter Movie:";
				cout<<endl;
				getline(cin,newName);
				getline(cin,newName);

				newName=space+newName;

				Movies.addMovie(date,newName);
				Movies.sortDate();
			}
			else if(command==2) {
				cout<<"Which Movie Do You Want To Delete:"<<endl;
				getline(cin,newName);
				getline(cin,newName);
				newName=space+newName;
				Movies.deleteMovie(newName);
				Movies.sortDate();
			}
			else if(command==3) {
				cout<<"Enter Movie Name:"<<endl;
				getline(cin,newName);
				getline(cin,newName);
				newName=space+newName;
				Movies.ChangeInfo(newName);
				Movies.sortDate();
			}
			else if(command==4) {
				Movies.sortDate();
				Movies.searchMovie();
			}	
			else if(command==5) {
				cout<<"*********************"<<endl;
				Movies.sortDate();
				Movies.printAll();
				cout<<"*********************"<<endl;
			}
			else if(command==6) {
				Movies.MoviefileOut(len);

			}
			else {
				cout<<"Wrong comment"<<endl;
			}

		}
		
		cout<<"İf You want TO Do Quiz press 2\n"<<endl;
		cout<<"Or press any number\n"<<endl;
		key=trueInt();

	}
	len=Movies.NumberOfMovie();

	while(key==2) {
		srand(time(0));
		cout<<"You have 10 question to solve"<<endl;
		while(numOfQuestion<10) {
			int r=rand();
			cout<<"*********************"<<endl;
			cout<<"Question)"<<numOfQuestion+1<<endl;
			questionStyle=1+(rand()%2);
			grade=grade+Movies.quizQuestion(len,r,questionStyle);
			cout<<"*********************"<<endl;
			numOfQuestion++;
		}

		if(grade>=90) 	   { cout<<"grade:"<<grade<<" **********	Excellent"<<endl; }
		else if(grade>=80) { cout<<"grade:"<<grade<<" ********	Good"<<endl; }
		else if(grade>=70) { cout<<"grade:"<<grade<<" ******	Not Bad"<<endl; }
		else if(grade>=60) { cout<<"grade:"<<grade<<" ****	Medium"<<endl; }
		else if(grade>=50) { 
			cout<<"grade:"<<grade<<" **		You Can do Better"<<endl; 
		}
		else if(grade>=40) { cout<<"grade:"<<grade<<" *		You are Merely Passed"<<endl; }
		else {  cout<<"grade:"<<grade<<" You have to study MORE!!!"<<endl; }
		cout<<"Do You want to do Another Game\n1)no\n2)yes"<<endl;
		key=trueInt();
		numOfQuestion=0;
	 }	

	return 0;
}





