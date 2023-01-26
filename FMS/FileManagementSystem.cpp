#include<iostream>
#include<cstring>
#include<cstdio>
#include <fstream>
#include <string>

using namespace std;

//Function to create file
void createFile(string fileName) {
    //creates file using ofstream object
    ofstream file(fileName);
    // If File is open, it means the file has been created
    if (!file.is_open()) {
        cout << "Error creating file" <<endl;
        return;
    }

    //Once file is created it opens the file
    file.close();
    cout << "File successfully created" << endl;
}

//Function to readFile
void readFile(string fileName) {
    //File is opened using ifstream object
    ifstream file(fileName);
    //Checks if the file is open
    if (!file.is_open()) {
        cout << "Error opening file" <<endl;
        return;
    }
    string line;
    //using while loop and getline it prints content of file to console
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

// Function to edit file
void editFile(string fileName, string newContent) {
    //Opens the file using ofstream
    ofstream file(fileName);
    //Checks if the file is open
    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }
    //newContent store input to file
    file << newContent;
    file.close();
    cout << "File successfully edited" << endl;   
}


//Function delte file
void deleteFile(string fileName) {
    //remove function is used to delete file; It takes c-style string
    if (remove(fileName.c_str()) != 0) {
        cout << "Error deleting file" << endl;
    }
    else {
        cout << "File successfully deleted" << endl;
    }
}

//Function to list files
void listFiles(){
    // This variable contains the path to the directory
    string path("\"E:\\code\\FMS\"");

    // The command which would do the file listing
    string command("dir /a-d ");

    // The path is appended after the command string
    command.append(path);

    // The string is converted to const char * as system
    const char* final_command = command.c_str();

    // Sending the final command as the arguemnt to the
    // system function
    system(final_command);
}

//Function to clear file content
void clearFile(string nm) {
    ofstream ofs;
    // Using Truncate any contents that existed in the file before it is open are discarded.
    ofs.open (nm, ofstream::out | ofstream::trunc);
    ofs.close();
}

int main()
{
//Introduction
cout<<endl;
cout<<"----------------------------------------------------------------------------"<<endl;
cout<<"\t\t\t DISTRIBUTED OPERATING SYSTEM \t\t\t\t\t\t"<<endl;
cout<<"\t\t\t\tDIGITAL ASSIGNMENT \t\t\t\t\t\t"<<endl;
cout<<"\t\t   TOPIC-  FILE MANAGEMENT SYSTEM \t\t\t\t\t\t"<<endl;
cout<<"----------------------------------------------------------------------------"<<endl;
cout<<endl;

//Menu
cout<<"[1] Create File"<<endl;
cout<<"[2] Read File"<<endl;
cout<<"[3] Edit File"<<endl;
cout<<"[4] Delete File"<<endl;
cout<<"[5] List Files"<<endl;
cout<<"[6] Clear File Content"<<endl;
cout<<"Enter number between [1-4] to perform actions corresponding to each number"<<endl;

int inp = 0;

//Loop continue taking values from user till exit request
while(inp != 7){
    cout<<endl;
    cout<<"Please enter a number:"<<endl;
    cin>>inp;
    cout<<endl;

    if(inp == 1){
        
        string fname = " ";
        cout<<"Give name to new file:"<<endl;
        cin>>fname;
        createFile(fname);
        cout<<"===== File Created ======"<<endl;
    
    } else if(inp == 2){
    
        string rfname = " ";
        cout<<"Enter name of file to read:"<<endl;
        cin>>rfname;
        readFile(rfname);
        cout<<"===== File Closed ====="<<endl;
    
    } else if(inp == 3){

        string efname = " ", cont = " ";
        cout<<"Name file to edit:"<<endl;
        cin>>efname;
        cin.ignore();
        cout<<"Write content to store in "<<efname<<": "<<endl;
        getline(cin,cont);
        editFile(efname, cont);
        cout<<"====== Editing Finish ======"<<endl;

    } else if(inp == 4){
    
        string dfname = " ";
        cout<<"Enter name of file to delete"<<endl;
        cin>>dfname;
        deleteFile(dfname);
        cout<<"===== Deleted ======"<<endl;
    
    } else if(inp == 5) {
        
        cout<<endl;
        listFiles();
        cout<<endl;

    } else if(inp == 6){

        string cfname = "";
        cout<<"Name of file to clear content:"<<endl;
        cin>>cfname;
        clearFile(cfname);
        cout<<"Preocess Complete!"<<endl;

    } else {
  
        cout<<"======== Exit ======="<<endl;
        break;
    
    }
}
}