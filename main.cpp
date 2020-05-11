#include <iostream>

#include <boost/thread.hpp>

using namespace std;

#if 0
boost::mutex mx;
#endif

template <long... nums> struct Multiply;

template <long first,long... last>
struct Multiply<first,last...>{
    static const long val = first * Multiply<last...>::val;
};

template<>
struct Multiply<>{
    static const long val = 1;
};


void wait(int sec){
    boost::this_thread::sleep(boost::posix_time::seconds(sec));
}

struct Date{
    constexpr Date(int y,int m,int d):year(y),month(m),day(d){}

    constexpr int GetYear() { return  year;}
    constexpr int GetMonth() const { return  month;}
    constexpr int GetDay() { return  day;}
private:
    int year;
    int month;
    int day;
};

constexpr int Fibonacci(int n){
    return (n==1) ? 1 :((n==2) ? 1 :(Fibonacci(n-1)) + Fibonacci(n-2));
}
constexpr Date PRCfound{1949,10,1};
constexpr int foundmonth = PRCfound.GetMonth();



/*test c++11 or boost*/
int main(int argc, const char * argv[]){
    cout << "Wait 3 seconds " << endl;
    wait(3);
    cout << "Done!" << endl;

    cout <<foundmonth<<endl;

    int fib[] = {
            Fibonacci(11),Fibonacci(12),
            Fibonacci(13),Fibonacci(14),
            Fibonacci(15),Fibonacci(16),
            Fibonacci(17),Fibonacci(18),
    };
    for (int i : fib) {
        cout << i << endl;
    }

    cout << Multiply<2,3,4,5>::val << endl;
    cout << Multiply<22,44,66,88,9>::val << endl;

    return 0;
}