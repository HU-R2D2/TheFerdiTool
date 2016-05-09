//
// Created by Ferdi on 09-May-16.
//

#include "../include/FaganInspectionTest.hpp"
#include "../include/FileSearcher.hpp"
#include "../include/LineLength.hpp"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
FaganInspectionTest::FaganInspectionTest()  {
    //ToDo Insert all inspections to run
    run_all_inspections();
}
void FaganInspectionTest::run_all_inspections()  {
    //ToDo get all files and run all inspections on each file
    FileSearcher files("E:\\Development\\HBO\\Year2\\BlokC\\ThemaOpdracht7-8\\Fagan-Lite-Tool\\test\\testfiles");
    for(std::string s : files.get_files())  {
        std::cout << s << std::endl;
        ifstream iFile(s);
        vector<string> file_contents;
        while(!iFile.eof()) {
            string s;
            getline(iFile, s);
            file_contents.push_back(s);
        }
        std::string file_content( (std::istreambuf_iterator<char>(iFile) ),
                                 (std::istreambuf_iterator<char>()    ) );
        XmlFileFormat xmlff;
        LineLength ll(xmlff, file_contents);
        ll.inspect();
        for(string s : xmlff.get_xml_data())    {
            cout << s << "\n";
        }
        //std::cout << file_content << std::endl;
    }
}