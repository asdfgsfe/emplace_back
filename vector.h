#ifndef __VECTOR__
#define __VECTOR__

#include <string.h>
#include <iostream>
#include <new>

//placement newµÄÓÃ·¨
//template<typename _Tp, typename... _Args>
//static construct(_Tp* __p, _Args&&... __args)
//{ ::new((void*)__p) _Tp(std::forward<_Args>(__args)...); }

template<typename T>
class vector
{
public:
	vector()
		: first_(new T[2]), last_(first_), end_(first_ + 2)
	{
	}

	template<typename ...Args>
	void emplace_back(Args&&... args)
	{
		if (size() == capacity()) 
		{
			reallocate();
		}
		::new((void*)last_) T(std::forward<Args>(args)...);
		++last_;
	}

	void push_back(const T &val) 
  {
		if (size() == capacity()) 
		{
			reallocate();
		}
		::new((void*)last_) T(val);
		++last_;
	}

	void push_back(T&& val) {
		if (size() == capacity()) 
		{
			reallocate();
		}
		::new((void*)last_) T(std::forward<T>(val));
		++last_;
	}

	void pop_back() 
  {
		--last_;
		*last_.~T();
	}
	
	void reallocate() 
  {
		int maxlen = capacity() + capacity() / 2;
		int len = size();
		T* cur = new T[maxlen];
		::memcpy(cur, first_, len * sizeof(T));
		delete [] first_;
		first_ = cur;
		last_ = first_ + len;
		end_ = first_ + maxlen;
	}


	int size() const { return last_ - first_ ;}
	int capacity() const { return end_ - first_; }

private:
	T* first_;
	T* last_;
	T* end_;
};


#endif //__VECTOR__
