#include<bits/stdc++.h>

using namespace std;

int  main(){
   map<string,int > dict;
   dict["tom"] = 21;
   dict["lily"] = 22;
   dict["bob"] = 23;
   if(dict.count("tom")){
       cout << "tom is " << dict["tom"] <<" years old" << endl;
   }

   for(map<string, int> :: iterator it = dict.begin();it != dict.end();++it){
       cout << it->first << " is "<< it->second << " years old" << endl;

   }
   dict.clear();
   return 0;
}