#pragma once

#include "entityx/Entity.h"

enum class NodeType
{
	ND_Small,
};

struct Node : public entityx::Component<Node>
{
	Node(NodeType type = NodeType::ND_Small);

	NodeType m_type;
};