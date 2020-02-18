#pragma once
template<class T>
class Ref
{
public: 
	int count = 1;
	T* object = nullptr;
	Ref(T* target) :object(target)
	{
	}
	inline void increase()
	{
		count++;
	}
	inline void decrese()
	{
		count--;
		if (count==0)
		{
			delete object;
			delete this;
		}
	}
	int getcount()
	{
		return count;
	}
};
template<class T>
class Lshard_ptr
{
public:
	Ref<T> *ref;
	Lshard_ptr()
	{
		ref =nullptr;
	}
	Lshard_ptr(T* other)
	{
		ref = new Ref<T>(other);
	}
	Lshard_ptr(const Lshard_ptr& other)
	{
		ref = other.ref;
		if (ref)
		{
			ref->increase();
		}
	}
	Lshard_ptr(Lshard_ptr&& other)
	{
		swap(ref,other.ref);
	}
	Lshard_ptr& operator=( const Lshard_ptr& other)
	{
		if (ref)
		{
			ref->decrese();
		}
		ref = other.ref;
		if (ref)
		{
			ref->increase();
		}
		return *this;
	}
	Lshard_ptr& operator=(Lshard_ptr&& other)
	{
		if (ref) ref->decrese();
		ref = other.ref;
		other.ref = nullptr;
		return *this;	
	}
	void swap(Lshard_ptr& other)
	{
		swap(ref,other.ref):
	}
	void reset(T* other=nullptr)
	{
		if (ref) ref->decrese();
		if (other)
		{
			ref = new Ref<T>(other);
		}
		else
		{
			ref = nullptr;
		}
	}
	T& operator*()
	{
		if (ref)
		{
			return *(ref->object);
		}
	}
	int use_count()
	{
		if (ref)
		{
			return ref->getcount();
		}
		return 0;
	}
	T* get()
	{
		if (ref) return ref->object;
		else return (T*)nullptr;
	}
	bool unique()
	{
		if (ref->getcount() == 0) return true;
		return false;
	}
	~Lshard_ptr()
	{
		if (ref){
			ref->decrese();
		}

	}

};