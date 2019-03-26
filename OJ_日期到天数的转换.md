# OJ_日期到天数的转换

[日期到天数的转换 牛客网](https://www.nowcoder.com/practice/769d45d455fe40b385ba32f97e7bcded?tpId=37&&tqId=21296&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking)

~~~C
/*
	>Plan:日期到天数的转换
	>Author:ADiiana
	>Time:3-19
*/
//判断闰年和平年，以及二月。
#include<iostream>
using namespace std;
class Date{
public:
    Date(int year, int month, int day)
    :m_year(year)
    ,m_Month(month)
    ,m_Day(day){}
    
    ~Date(){}
    //进行转换，并改变m_outDay的值,失败返回-1，成功返回0
     int iConverDateToDay(){
         if(m_year == 0 || m_Month == 0 || m_Day == 0){
         return -1;
    }
    //判断平年还是闰年;4年一闰，百年不闰，400年一闰，改变月份。
    int wholeMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((m_year % 4 == 0 && m_year % 100 != 0) || m_year % 400 == 0){
        wholeMonth[1] = 29;
    }
    for(int i = 0; i < m_Month - 1; i++){
        m_outDay += wholeMonth[i];
    }
    m_outDay += m_Day;
    return 0;
     }
     int getOutDay(){
        return m_outDay;
    }
private:
     int m_year;
     int m_Month;
     int m_Day;
     int m_outDay = 0;
};

int main(){
    int year;
    int Month;
    int Day;
    while(cin >> year >> Month >> Day){
        Date date(year, Month, Day);
    int flag = date.iConverDateToDay();
    if(flag == 0){
        //成功返回
        cout << date.getOutDay() << endl;
    }
    else{
        //数据错误
        return 0;
    }
    }
    
    
	system("pause");
	return 0;
}
~~~

