/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifndef NDN_NRT_HELPER_H
#define NDN_NRT_HELPER_H


#include "ns3/node-container.h"

#include "ns3/ndnSIM/model/ndn-common.hpp"


namespace ns3 {
namespace ndn {

/**
 * @ingroup ndn-helpers
 * @brief Network Region Table Helper
 *
 * The NRT Helper interacts directly with Network Region Table by passing parameters
 * to NRT functions in order to add/remove a prefix to/from the table in one node or
 * a node container
 */

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
