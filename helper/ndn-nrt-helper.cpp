/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "ndn-nrt-helper.hpp"
#include "ns3/ndnSIM/model/ndn-l3-protocol.hpp"
#include "ns3/ndnSIM/NFD/daemon/fw/forwarder.hpp"


namespace ns3 {
namespace ndn {

NS_LOG_COMPONENT_DEFINE("ndn.NrtHelper");

void
NetworkRegionTableHelper::AddRegionName(Ptr<Node> node, const Name& regionName){

    NS_LOG_LOGIC("Node [" << node->GetId() << "]$ RegionName " << regionName << " is added into NetworkRegionTable ");

    Ptr<L3Protocol> l3protocol = node->GetObject<L3Protocol>();
    NS_ASSERT_MSG(l3protocol != 0, "Ndn stack should be installed on the node");

    node->GetObject<L3Protocol>()->getForwarder()->getNetworkRegionTable().insert(regionName);
}

void
NetworkRegionTableHelper::AddRegionName(NodeContainer &c, const ndn::Name& regionName){

    for(NodeContainer::iterator i = c.begin(); i != c.End(); ++i){
        AddRegionName(*i, regionName);
    }
}

void
NetworkRegionTableHelper::RemoveRegionName(Ptr<Node> node, const Name& regionName){

    NS_LOG_LOGIC("Node [" << node->GetId() << "]$ RegionName " << regionName << " is removed from NetworkRegionTable ");

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
