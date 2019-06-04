# OJ_空格替换

~~~C++
class Solution {
public:
        void replaceSpace(char *str,int length) {
        std::vector<std::string> ret;
        std::string value(str);
        int i;
        int pos = -1;

        for(i = 0; i < value.length(); i = pos + 1){
            if(value.find(" ", pos + 1) != std::string::npos){
                pos = value.find(" ", pos + 1);
                ret.push_back(value.substr(i, pos - i) + "");
        }
        else{
            ret.push_back(value.substr(i));
            break;
            }
        }
        if(pos + 1 == value.length()){
            ret.resize(ret.size() + 1);
        }
        //str = (char*)malloc(ret.size() * 3 + length);
        std::string tmp;
        for(i = 0; i < ret.size(); i++){
            tmp += ret[i];
            if(i + 1 == ret.size()){
                break;    
            }
            tmp += "%20";
        }
        memcpy(str, (char*)tmp.c_str(), (tmp.length() + 1));
    }
};
~~~

