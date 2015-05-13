#include "Node.h"
#include "RenderEngine.h"
#include "CustomUtils.h"

Node::Node()
	:Ref()
{
	_name = "";
	_tag = -1;
	_parent = nullptr;
	pos = Vec2();
	dst_pos = Vec2();
}

Node::~Node()
{

}

void Node::addChild(Node* node)
{
	node->_parent = this;
	_subNode.push_back(node);
	node->retain();
}

void Node::addChild( Node* node, int z )
{
	addChild(node);
	node->_z = z;
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

void Node::sendRenderCommand()
{
	for (int z=MIN_Z; z<0; z++)
	{
		for (int i=0; i<_subNode.size(); i++)
		{
			Node* node = _subNode.at(i);
			if (node->_z == z)
			{
				node->sendRenderCommand();
			}
		}
	}

	_renderEngine->sendCommand(
		this,
		_customUtils->transGlobalVec2(this,this->pos)
		);

	for (int z=0; z<MAX_Z; z++)
	{
		for (int i=0; i<_subNode.size(); i++)
		{
			Node* node = _subNode.at(i);
			if (node->_z == z)
			{
				node->sendRenderCommand();
			}
		}
	}
}
