#include "IRremote.h"

//==============================================================================
//               W   W  H   H  Y   Y N   N TTTTT EEEEE  RRRRR
//               W   W  H   H   Y Y  NN  N   T   E      R   R
//               W W W  HHHHH    Y   N N N   T   EEE    RRRR
//               W W W  H   H    Y   N  NN   T   E      R  R
//                WWW   H   H    Y   N   N   T   EEEEE  R   R
//==============================================================================
// Whynter A/C ARC-110WD added by Francesco Meschia
// see https://docs.google.com/spreadsheets/d/1dsr4Jh-nzC6xvSKGpLlPBF0NRwvlpyw-ozg8eZU813w/edit#gid=0

#define WHYNTER_BITS            32
#define WHYNTER_HEADER_MARK   2850
#define WHYNTER_HEADER_SPACE  2850
#define WHYNTER_BIT_MARK       750
#define WHYNTER_ONE_SPACE     2150
#define WHYNTER_ZERO_SPACE     750

//+=============================================================================
void IRsend::sendWhynter(unsigned long data, int nbits) {
    // Set IR carrier frequency
    enableIROut(38);

    noInterrupts();

    // Start
    mark(WHYNTER_BIT_MARK);
    space(WHYNTER_ZERO_SPACE);

    // Header
    mark(WHYNTER_HEADER_MARK);
    space(WHYNTER_HEADER_SPACE);

    // Data + stop bit
    sendPulseDistanceWidthData(WHYNTER_BIT_MARK, WHYNTER_ONE_SPACE, WHYNTER_BIT_MARK, WHYNTER_ZERO_SPACE, data, nbits, MSB_FIRST,
    SEND_STOP_BIT);

    interrupts();
}

#if DECODE_WHYNTER
//+=============================================================================
bool IRrecv::decodeWhynter() {

    // Check we have the right amount of data (68). The +4 is for initial gap, start bit mark and space + stop bit mark.
    if (decodedIRData.rawDataPtr->rawlen != (2 * WHYNTER_BITS) + 4) {
        return false;
    }

    // Sequence begins with a bit mark and a zero space
    if (!MATCH_MARK(decodedIRData.rawDataPtr->rawbuf[1], WHYNTER_BIT_MARK)
            || !MATCH_SPACE(decodedIRData.rawDataPtr->rawbuf[2], WHYNTER_HEADER_SPACE)) {
        DBG_PRINT(F("Whynter: "));
        DBG_PRINTLN(F("Header mark or space length is wrong"));
        return false;
    }

    if (!decodePulseDistanceData(WHYNTER_BITS, 3, WHYNTER_BIT_MARK, WHYNTER_ONE_SPACE, WHYNTER_ZERO_SPACE, MSB_FIRST)) {
        return false;
    }

    // trailing mark / stop bit
    if (!MATCH_MARK(decodedIRData.rawDataPtr->rawbuf[3 + (2 * WHYNTER_BITS)], WHYNTER_BIT_MARK)) {
        DBG_PRINTLN(F("Stop bit mark length is wrong"));
        return false;
    }

    // Success
    decodedIRData.flags = IRDATA_FLAGS_IS_MSB_FIRST;
    decodedIRData.numberOfBits = WHYNTER_BITS;
    decodedIRData.protocol = WHYNTER;
    return true;
}
#endif // DECODE_WHYNTER
