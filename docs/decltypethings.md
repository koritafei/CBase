### 基本使用
```cpp
decltype (expression)
```
1. 查询推导表达式的类型。
```cpp
int i = 4;
decltype(i) a = 20;
```
2. 与`using/typedef`结合定义类型
```cpp
using size_t = decltype(sizeof(0));//sizeof(a)的返回值为size_t类型
using ptrdiff_t = decltype((int*)0 - (int*)0);
using nullptr_t = decltype(nullptr);
vector<int >vec;
typedef decltype(vec.begin()) vectype;
for (vectype i = vec.begin; i != vec.end(); i++)
{
//...
}
```
3. 重用匿名类型：
```cpp
struct 
{
    int d ;
    double b;
}anon_s;
```
借助`decltype`重新使用这个匿名结构体：
```cpp
decltype(anon_s) as ;//定义了一个上面匿名的结构体
```

4. 泛型编程中结合`auto`， 用于追踪函数的返回值类型
```cpp
template <typename T>
auto multiply(T x, T y)->decltype(x*y)
{
	return x*y;
}
```
#### 判别规则
对`decltype(e)`,判别规则受如下条件影响：
> 1. 如果`e`是一个没有带括号的标记符表达式或类成员访问表达式，那么`decltype(e)`就是`e`命名的实体的类型；
> 2. 如果`e`是一个函数重载，编译报错；
> 3. 假设`e`的类型为`T`：
> 3.1. 如果`e`是一个将亡值，那么`decltype(e)`为`T&&`;
> 3.2. 如果`e`是一个左指，那么`decltype(e)`为`T&`;
> 3.3. 否则`decltypre(e)`为`T`.

```cpp
int i = 4;
int arr[5] = { 0 };
int *ptr = arr;
struct S{ double d; }s ;
void Overloaded(int);
void Overloaded(char);//重载的函数
int && RvalRef();
const bool Func(int);

//规则一：推导为其类型
decltype (arr) var1; //int[] 标记符表达式

decltype (ptr) var2;//int *  标记符表达式

decltype(s.d) var3;//doubel 成员访问表达式

//decltype(Overloaded) var4;//重载函数。编译错误。

//规则二：将亡值。推导为类型的右值引用。

decltype (RvalRef()) var5 = 1;

//规则三：左值，推导为类型的引用。

decltype ((i))var6 = i;     //int&

decltype (true ? i : i) var7 = i; //int&  条件表达式返回左值。

decltype (++i) var8 = i; //int&  ++i返回i的左值。

decltype(arr[5]) var9 = i;//int&. []操作返回左值

decltype(*ptr)var10 = i;//int& *操作返回左值

decltype("hello")var11 = "hello"; //const char(&)[9]  字符串字面常量为左值，且为const左值。


//规则四：以上都不是，则推导为本类型

decltype(1) var12;//const int

decltype(Func(1)) var13=true;//const bool

decltype(i++) var14 = i;//int i++返回右值
```


