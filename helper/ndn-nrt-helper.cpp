/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "ndn-nrt-helper.hpp"

#include "ns3/node-container.h"


namespace ns3 {
namespace ndn {

void
NetworkRegionTableHelper::AddRegionName(Ptr<Node>& node, const Name& regionName){

    Ptr<L3Protocol> l3protocol = node->GetObject<L3Protocol>();
    NS_ASSERT_MSG(l3protocol != 0, "Ndn stack should be installed on the node");

    node->GetObject<L3Protocol>()->getForwarder()->getNetworkRegionTable().insert(regionName);
}

void
NetworkRegionTableHelper::AddRegionName(NodeContainer &c, const ndn::Name &regionName){

    for(NodeContainer::iterator i = c.begin(); i != c.End(); ++i){
        AddRegionName(*i, regionName);
    }
}

void
NetworkRegionTableHelper::RemoveRegionName(Ptr<Node> node, const Name& regionName){
    Ptr<L3Protocol> l3protocol = node->GetObject<L3Protocol>();
    NS_ASSERT_MSG(l3protocol != 0, "Ndn stack should be installed on the node");

    node->GetObject<L3Protocol>()->getForwarder()->getNetworkRegionTable().erase(regionName);
}

void
NetworkRegionTableHelper::RemoveRegionName(NodeContainer &c, const ndn::Name &regionName){
    for(NodeContainer::iterator i = c.begin(); i != c.End(); ++i){
        RemoveRegionName(*i, regionName);
    }
}

}
}
