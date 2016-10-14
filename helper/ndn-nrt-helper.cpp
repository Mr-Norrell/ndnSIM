/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- *//**
 * Copyright (c) 2011-2016  Regents of the University of California.
 *
 * This file is part of ndnSIM. See AUTHORS for complete list of ndnSIM authors and
 * contributors.
 *
 * ndnSIM is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * ndnSIM is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * ndnSIM, e.g., in COPYING.md file.  If not, see <http://www.gnu.org/licenses/>.
 **/

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

void
NetworkRegionTableHelper::EmptyNetworkRegionTable(Ptr<Node> node){
    NS_LOG_LOGIC("Node [" << node->GetId() << "]$ NetworkRegionTable is cleared");

    Ptr<L3Protocol> l3protocol = node->GetObject<L3Protocol>();
    NS_ASSERT_MSG(l3protocol != 0, "Ndn stack should be installed on the node");

    node->GetObject<L3Protocol>()->getForwarder()->getNetworkRegionTable().clear();

}

void
NetworkRegionTableHelper::EmptyNetworkRegionTable(NodeContainer &c){

    for(NodeContainer::iterator i = c.begin(); i != c.End(); ++i){
        EmptyNetworkRegionTable(*i);
    }
}

}
}
