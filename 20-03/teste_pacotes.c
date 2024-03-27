// How to use: 
// $ make
// $ ./testepacotes.out
#include "pacote.h"
#define DATA_SIZE 10

int main(){
    printf("ACK PACKET: \n\n");
    struct Packet* acknowledge_packet = createACKPacket(0, 10, 20);
    printPacketInformation(acknowledge_packet);
    deletePacket(acknowledge_packet);
    printf("\n");
    printf("DATA PACKET: \n\n");
    char data[DATA_SIZE];
    for(int i = 0; i < DATA_SIZE; i++){
        data[i] = i;
    }
    struct Packet* data_packet = createDataPacket(5, 50, 80);
    writeData(data_packet, data, DATA_SIZE);
    printPacketInformation(data_packet);
    printf("\n");
    printf("CLONE PACKET: \n\n");
    struct Packet* clone_packet = clonePacket(data_packet);
    printPacketInformation(clone_packet);
    deletePacket(data_packet);
    deletePacket(clone_packet);
    return 0;
}
