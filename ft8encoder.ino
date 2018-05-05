/*
T/R sequence length: 15 s (decode included)
Message length: 75 bits + 12 bits CRC = 87 bits.
FEC code: LDPC(174,87) = 174 bits 
Modulation: 58 3-bit FSK-8 symbols  
Keying rate = tone spacing = 6.25 Hz, 0.16 seconds/symbol
Occupied bandwidth: 50 Hz
? Synchronization: three 7x7 Costas arrays (start, middle, end of Tx)
Transmission duration: 79 bits * 1920 point/12000samples/sec = 12.64 s
 
insert three 7-symbol Costas sync arrays at symbol #s 0, 36, 72 of final signal
thus: 79 FSK-8 symbols


	i = 0; i < 7; i++
        MGMSymCar[(uint8_t) msgNo][i] = pgm_read_byte(&costas[i]);
        MGMSymCar[(uint8_t) msgNo][i + 36] = pgm_read_byte(&costas[i]);
        MGMSymCar[(uint8_t) msgNo][i + 72] = pgm_read_byte(&costas[i]);
    


	i = 0; i < 19; i += 3
        uint32_t value = (uint32_t) (codewordPacked[i] & 0xFF) << 16;
        value += (uint32_t) (codewordPacked[i + 1] & 0xFF) << 8;
        value +=(uint32_t) codewordPacked[i + 2] & 0xFF;

*/
