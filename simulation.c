#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct
{
    int sourceNode;
    int destinationNode;
    char payload[256]; // Payload field added
} Packet;

typedef struct
{
    int destinationNode;
    int nextHop;
} RoutingTableEntry;

typedef struct
{
    int nodeId;
    RoutingTableEntry *routingTable; // Use dynamic memory allocation for routing table
} Node;

void initializeNetwork(Node nodes[], int nodeCount)
{
    for (int i = 0; i < nodeCount; ++i)
    {
        nodes[i].nodeId = i + 1;
        nodes[i].routingTable = (RoutingTableEntry *)malloc(nodeCount * sizeof(RoutingTableEntry));

        for (int j = 0; j < nodeCount; ++j)
        {
            nodes[i].routingTable[j].destinationNode = j + 1;
            nodes[i].routingTable[j].nextHop = (i + 1) % nodeCount + 1;
        }
    }
}

void printRoutingTable(RoutingTableEntry routingTable[], int nodeCount)
{
    printf("Routing Table:\n");
    printf("| Destination | Next Hop |\n");
    printf("|-------------|----------|\n");

    for (int i = 0; i < nodeCount; ++i)
    {
        printf("| %-11d | %-8d |\n", routingTable[i].destinationNode, routingTable[i].nextHop);
    }

    printf("\n");
}

void printNetwork(Node nodes[], int nodeCount)
{
    for (int i = 0; i < nodeCount; ++i)
    {
        printf("Node %d\n", nodes[i].nodeId);
        printRoutingTable(nodes[i].routingTable, nodeCount);
    }
}

void switchPackets(Node nodes[], Packet packets[], int packetCount, int nodeCount)
{
    printf("Packet Switching Simulation\n");

    for (int i = 0; i < packetCount; ++i)
    {
        Packet packet = packets[i];
        printf("Processing Packet %d from Node %d to Node %d with Payload: %s\n",
               i + 1, packet.sourceNode, packet.destinationNode, packet.payload);

        Node *sourceNode = NULL;
        for (int j = 0; j < nodeCount; ++j)
        {
            if (nodes[j].nodeId == packet.sourceNode)
            {
                sourceNode = &nodes[j];
                break;
            }
        }

        if (sourceNode == NULL)
        {
            printf("Error: Source node not found.\n");
            continue;
        }

        int currentNodeId = packet.sourceNode;
        int iterationCount = 0;

        do
        {
            int nextHop = -1;
            for (int j = 0; j < nodeCount; ++j)
            {
                if (sourceNode->routingTable[j].destinationNode == packet.destinationNode)
                {
                    nextHop = sourceNode->routingTable[j].nextHop;
                    break;
                }
            }

            if (nextHop == -1)
            {
                printf("Error: Next hop not found in the routing table.\n");
                break;
            }

            if (iterationCount >= nodeCount)
            {
                break;
            }

            printf("Packet switched from Node %d to Node %d\n", currentNodeId, nextHop);

            currentNodeId = nextHop;

            for (int j = 0; j < nodeCount; ++j)
            {
                if (nodes[j].nodeId == currentNodeId)
                {
                    sourceNode = &nodes[j];
                    break;
                }
            }

            iterationCount++;
            sleep(1); // time delay to simulate network latency

        } while (currentNodeId != packet.destinationNode || packet.sourceNode == packet.destinationNode);

        printf("Packet reached the destination Node %d\n", packet.destinationNode);
        printf("-------------------------------------------------\n");
    }
}

int main()
{
    int MAX_NODES,MAX_PACKETS;
    printf("Enter the number of nodes: ");
    scanf("%d", &MAX_NODES);

     printf("Enter the number of packets: ");
    scanf("%d", &MAX_PACKETS);

    // Initialize network
    Node nodes[MAX_NODES];
    initializeNetwork(nodes, MAX_NODES);

    // Print initial network details
    printf("Initial Network Configuration:\n");
    printNetwork(nodes, MAX_NODES);

    // Simulate generating four packets
    Packet packets[MAX_PACKETS];

    // Generate one packet with source and destination nodes as the same
    packets[0].sourceNode = rand() % MAX_NODES + 1;
    packets[0].destinationNode = packets[0].sourceNode;
    sprintf(packets[0].payload, "Hello!");

    // Generate other packets with different source and destination nodes
    for (int i = 1; i < MAX_PACKETS; ++i)
    {
        do
        {
            packets[i].sourceNode = rand() % MAX_NODES + 1;
            packets[i].destinationNode = rand() % MAX_NODES + 1;
        } while (packets[i].sourceNode == packets[i].destinationNode);

        switch (i)
        {
        case 1:
            sprintf(packets[i].payload, "Welcome");
            break;
        case 2:
            sprintf(packets[i].payload, "Namaskar");
            break;
        case 3:
            sprintf(packets[i].payload, "Today, We have PBL");
            break;
        case 4:
            sprintf(packets[i].payload, "Packet Switching");
            break;
        case 5:
            sprintf(packets[i].payload, "To err is Human");
            break;
        case 6:
            sprintf(packets[i].payload, "Good Luck");
            break;
        case 7:
            sprintf(packets[i].payload, "All the best");
            break;
        case 8:
            sprintf(packets[i].payload, "Today is Wednesday");
            break;
        case 9:
            sprintf(packets[i].payload, "Today is 29-11-2023");
            break;
        case 10:
            sprintf(packets[i].payload, "Thanks");
            break;
        default:
            sprintf(packets[i].payload, "Data%d", i);
            break;
        }
    }

    // Switch the generated packets
    switchPackets(nodes, packets, MAX_PACKETS, MAX_NODES);

    // Free dynamically allocated memory
    for (int i = 0; i < MAX_NODES; ++i)
    {
        free(nodes[i].routingTable);
    }

    return 0;
}
