#include <iostream>

using namespace std;

template <typename T, size_t S>
class ArrayItrator
{
public:
	using ValueType = T;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;
	ArrayItrator(PointerType ptr, size_t S = 0) :m_ptr(ptr + S), idx(S)
	{

	}
	ArrayItrator& operator++()
	{
		m_ptr++;
		return *this;
	}
	ArrayItrator operator++(int)
	{
		ArrayItrator temp = *this;
		++(*this);
		return temp;
	}
	ArrayItrator& operator--()
	{
		m_ptr--;
		return *this;
	}
	ArrayItrator operator--(int)
	{
		ArrayItrator temp = *this;
		--(*this);
		return temp;
	}
	ReferenceType operator[](int index)
	{
		return *(m_ptr + index);
	}
	PointerType operator->()
	{
		return m_ptr;
	}
	ReferenceType operator*()
	{
		return *m_ptr;
	}
	bool operator==(const  ArrayItrator& other) const
	{
		return m_ptr == other.m_ptr;
	}
	bool operator!=(const  ArrayItrator& other) const
	{
		return !(*this == other);
	}
private:
	PointerType m_ptr;
	size_t idx;
};
template< typename T, size_t S>
class Array
{
public:
	using ValueType = T;
	using Iterator = ArrayItrator<T, S>;
	Array()
	{

	}
	constexpr size_t size() const
	{
		return S;
	}

	T& operator[](size_t index)
	{
		return m_Data[index];
	}
	const T& operator[](size_t index) const
	{
		return m_Data[index];
	}
	T* data()
	{
		return m_Data;
	}
	const T* data() const
	{
		return m_Data;
	}
	Iterator begin()
	{
		return Iterator(m_Data);
	}
	Iterator end()
	{
		return Iterator(m_Data, S);
	}
private:
	T m_Data[S];

};

int main()
{
	Array <int, 5>aa;
	aa[0] = 25;
	aa[1] = 50;
	aa[2] = 75;
	aa[3] = 100;
	aa[4] = 125;

	Array<int, 5>::Iterator it = aa.begin();
	Array<int, 5>::Iterator it_end = aa.end();
	int i = 0;
	while (it != it_end)
	{
		cout << *it << endl;
		it++;
	}
}
