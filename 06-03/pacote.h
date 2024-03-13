#ifndef PACOTE_H
#define PACOTE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define ACK_PACKET 0
#define DATA_PACKET 1
#define PAYLOAD_MAX_SIZE 100

struct Packet {
    uint8_t id;
    uint8_t type;
    uint32_t source_addr;
    uint32_t dest_addr;
    uint8_t payload_size;
    void* payload;
};

struct Packet* createDataPacket(uint8_t id, uint32_t source_addr, uint32_t dest_addr){
    struct Packet* packet = (struct Packet*) malloc(sizeof(struct Packet));
    packet->id = id;
    packet->type = DATA_PACKET;
    packet->source_addr = source_addr;
    packet->dest_addr = dest_addr;
    packet->payload_size = 0;
    packet->payload = NULL;
    return packet;
}

struct Packet* createACKPacket(uint8_t id, uint32_t source_addr, uint32_t dest_addr){
    struct Packet* packet = (struct Packet*) malloc(sizeof(struct Packet));
    packet->id = id;
    packet->type = ACK_PACKET;
    packet->source_addr = source_addr;
    packet->dest_addr = dest_addr;
    packet->payload_size = 0;
    packet->payload = NULL;
    return packet;
}

struct Packet* clonePacket(struct Packet* packet){
    struct Packet* new_packet = malloc(sizeof(struct Packet));
    memcpy(new_packet, packet, sizeof(struct Packet));
    if(packet->type == DATA_PACKET){
        new_packet->payload = malloc(packet->payload_size);
        memcpy(new_packet->payload, packet->payload, packet->payload_size);
    }
    return new_packet;
}

void writeData(struct Packet* packet, char data[], int size){
    if(packet->type == ACK_PACKET)
    {
        fprintf(stderr, "Trying to write data on acknowledge packet.\n");
        return;
    }
    if(size > PAYLOAD_MAX_SIZE){
        fprintf(stderr, "Trying to write data greater than allowed limit (%d bytes) on packet. The data will be truncated.\n", PAYLOAD_MAX_SIZE);
        size = PAYLOAD_MAX_SIZE;
    }
    packet->payload = malloc(size);
    packet->payload_size = size;
    memcpy(packet->payload, data, size);
}

void deletePacket(struct Packet* packet){
    free(packet->payload);
    free(packet);
}

void printPacketInformation(struct Packet* packet){
    printf("Packet pointer: %p\n", packet);
    printf("Packet type: %s\n", packet->type == ACK_PACKET?"ACK":"DATA");
    printf("ID: %d\n", packet->id);
    printf("Source Address: %d\n", packet->source_addr);
    printf("Destination Address: %d\n", packet->dest_addr);
    if(packet->type == ACK_PACKET){
        return;
    }
    printf("Payload Size: %d\n", packet->payload_size);
    printf("Payload pointer: %p\n", packet->payload);
    printf("Payload: ");
    char* payload = (char*) packet->payload;
    for(int i = 0; i < packet->payload_size; i++)
        printf("%d ", payload[i]);
    printf("\n");
}


#endif
