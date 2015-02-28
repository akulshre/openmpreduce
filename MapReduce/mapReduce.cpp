#include "mapReduce.h"

mapReduce::mapReduce(){

}

int main(){

	mapReduce *mapper = new mapReduce;
	//cout<<filename<<"\n";
	//mapper->fileRead(filename);
	mapper->populateFileVector();
	mapper->printQ(mapper->fileNameQ);
	mapper->fileRead((mapper->fileNameQ[0].word));
}

void mapReduce::fileRead(string filename){
	//printf("Reach here\n");
	//ifstream input;
	cout<<filename.c_str()<<endl;
	ifstream ifs(filename.c_str());
//	ifs.open(filename.c_str());
	string word;
	while(ifs >> word){
		cout<<word<<endl;
	}
	ifs.close();
}

void mapReduce::populateFileVector(){
	DIR *dir;
	struct dirent *entry;
	string dir_path = "/home/min/a/akulshre/MapReduce/filelist/";
	if((dir = opendir("/home/min/a/akulshre/MapReduce/filelist"))){
		while((entry = readdir(dir)) !=NULL){
		 	DATA fileEntry;
			if((strcmp(entry->d_name,".")) && (strcmp(entry->d_name,".."))){
				fileEntry.word = dir_path + entry->d_name;
				fileNameQ.push_back(fileEntry);	
			}
		}
	}
	else{
		perror(" ");
		exit(EXIT_FAILURE);
	}
}

void mapReduce::printQ(vector<DATA> printQueue){
	vector<int>::size_type sz = printQueue.size();

	for (int i=0;i<sz;i++){
		cout << printQueue[i].word << endl;
	}
}
