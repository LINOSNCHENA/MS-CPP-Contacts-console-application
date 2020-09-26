//#include <vector>
//#include <iostream>
//#include <algorithm>
//#include <boost/shared_ptr.hpp>
//
//struct Foo
//{
//	Foo(int _x) : x(_x) {}
//	~Foo()
//	{
//		std::cout << "Destructing a Foo with x=" << x << "\n";
//	}
//	int x;
//};
//
//typedef boost::shared_ptr<Foo> FooPtr;
//
//struct FooPtrOps
//{
//	bool operator()(const FooPtr& a, const FooPtr& b)
//	{
//		return a->x < b->x;
//	}
//
//	void operator()(const FooPtr& a)
//	{
//		std::cout << " " << a->x;
//	}
//};
//
//int main()
//{
//	std::vector<FooPtr> foo_vector;
//
//	foo_vector.push_back(FooPtr(new Foo(3)));
//	foo_vector.push_back(FooPtr(new Foo(2)));
//	foo_vector.push_back(FooPtr(new Foo(1)));
//
//	std::cout << "Original foo_vector:";
//	std::for_each(foo_vector.begin(), foo_vector.end(), FooPtrOps());
//	std::cout << "\n";
//
//	std::sort(foo_vector.begin(), foo_vector.end(), FooPtrOps());
//
//	std::cout << "Sorted foo_vector:";
//	std::for_each(foo_vector.begin(), foo_vector.end(), FooPtrOps());
//	std::cout << "\n";
//	system("pause");
//	return 0;
//}