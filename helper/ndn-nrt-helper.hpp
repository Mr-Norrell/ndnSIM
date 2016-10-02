/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifndef NDN_NRT_HELPER_H
#define NDN_NRT_HELPER_H


#include "ns3/ndnSIM/model/ndn-common.hpp"

#include "ns3/node.h"
#include "ns3/ptr.h"
#include "ns3/node-container.h"

#include "ns3/ndnSIM/model/ndn-l3-protocol.hpp"
#include "ns3/ndnSIM/NFD/daemon/fw/forwarder.hpp"
#include "ns3/ndnSIM/NFD/daemon/table/network-region-table.hpp"

namespace ns3 {
namespace ndn {

class NetworkRegionTableHelper
{
public:
    static void
    AddRegionName(Ptr<Node> node, const Name& regionName);

    static void
    AddRegionName(NodeContainer& c, const Name& regionName);

    static void
    RemoveRegionName(Ptr<Node> node, const Name& regionName);

    static void
    RemoveRegionName(NodeContainer& c, const Name& regionName);


};

}
}

#endif // NDN_NRT_HELPER_H
