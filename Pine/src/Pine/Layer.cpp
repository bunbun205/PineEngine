#include "pinepch.hpp"
#include "Layer.hpp"

namespace Pine {

Layer::Layer(const std::string &name)
	: m_DebugName(name)
{
}

Layer::~Layer()
{
	// Cleanup code can go here if needed
}


}