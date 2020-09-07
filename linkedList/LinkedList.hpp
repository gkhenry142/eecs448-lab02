/**
*	@author 
*	@date 
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	// TODO 
	int count = 0;
	Node<T>* temp = nullptr;
	temp = m_front;
	
	while(temp!=nullptr)
	{
		temp = temp->getNext();
		count = count + 1;
	}

	return(count);
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;

	// TODO 
	for(int i=0; i<(size()); i++)
	{
		if(temp->getValue()== value)
		{
			return (true);
		}
	}

	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	bool isRemoved = false;

	// TODO 
	if(m_front == nullptr)
	{
		return (false);
	}
	else
	{
		secondintoLast = m_front;
		if(size() == 1)
		{
			secondintoLast = m_front;
			delete secondintoLast;
			m_front = nullptr;
			m_size--;
			return (true);
		}
		for(int i=0;i<size();i++)
		{
			if(i==size()-2)
			{
				lastNode=secondintoLast->getNext();
			}
			secondintoLast = secondintoLast -> getNext();
		}
		delete secondintoLast;
		lastNode -> setNext(nullptr);
		m_size--;
	}

	return(isRemoved);
}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
