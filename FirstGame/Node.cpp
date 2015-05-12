#include "Node.h"

Node::Node()
	:Ref()
{
	_name = "";
	_tag = -1;
	_parent = nullptr;
}

void Node::addChild(Node* node)
{
	node->_parent = this;
	_subNode.push_back(node);
	node->retain();
}

void Node::releaseChild(Node* node)
{
	for (int i = 0; i < _subNode.size(); i++)
	{
		Node*& obj = _subNode.at(i);
		if (node == obj)
		{
			obj->release();
			_subNode.erase(_subNode.begin() + i);
			break;
		}
	}
}

void Node::releaseChild(string name)
{
	for (int i = 0; i < _subNode.size(); i++)
	{
		Node*& obj = _subNode.at(i);
		if (name.compare(obj->_name))
		{
			obj->release();
			_subNode.erase(_subNode.begin() + i);
			break;
		}
	}
}

void Node::releaseChild(int tag)
{
	for (int i = 0; i < _subNode.size(); i++)
	{
		Node*& obj = _subNode.at(i);
		if (tag == obj->_tag)
		{
			obj->release();
			_subNode.erase(_subNode.begin() + i);
			break;
		}
	}
}

Node* Node::searchChild(string name)
{
	for (int i = 0; i < _subNode.size(); i++)
	{
		Node* obj = _subNode.at(i);
		if (name.compare(obj->_name))
		{
			return obj;
		}
	}
}

Node* Node::searchChild(int tag)
{
	for (int i = 0; i < _subNode.size(); i++)
	{
		Node* obj = _subNode.at(i);
		if (tag == obj->_tag)
		{
			return obj;
		}
	}
}
