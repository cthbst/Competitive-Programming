class Solution {
public:
    bool isLeap(int year){
        if (year % 4) return 0;
        if (year % 100 == 0 && year % 400 != 0 ) return 0;
        return 1;
    }
    
    string dayOfTheWeek(int day, int month, int year) {
        int D = 0;
        for (int i=1970; i<year; i++){
            if (isLeap(i)) D += 366;
            else D += 365;
        }
        int days_of_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (isLeap(year)) days_of_month[2]++;
        for (int i=0; i<month; i++) D += days_of_month[i];
        D += day;
        
        const string daysOfWeek[] = {
            "Sunday",
            "Monday",
            "Tuesday",
            "Wednesday",
            "Thursday",
            "Friday",
            "Saturday"
        };
        
        return daysOfWeek[(D+3)%7];
    }
};
