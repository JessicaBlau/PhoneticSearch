//
// Created by jblau on 7/15/2020.
//

#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;


TEST_CASE("Test happy") {
    string text = "xxx happy yyy";
            CHECK(find(text, "happy") == string("happy"));
            CHECK(find(text, "habby") == string("happy"));
            CHECK(find(text, "hapby") == string("happy"));
            CHECK(find(text, "habpy") == string("happy"));
            CHECK(find(text, "haffy") == string("happy"));
            CHECK(find(text, "hapfy") == string("happy"));
            CHECK(find(text, "hafpy") == string("happy"));
            CHECK(find(text, "happy") == string("happy"));
            CHECK(find(text, "happi") == string("happy"));
            CHECK(find(text, "Happi") == string("happy"));
            CHECK(find(text, "HAPPI") == string("happy"));
            CHECK(find(text, "HaPpI") == string("happy"));
            CHECK(find(text, "HAppi") == string("happy"));
            CHECK(find(text, "happI") == string("happy"));
            CHECK(find(text, "habbi") == string("happy"));
}

TEST_CASE("Test dont and be") {
    string text = "dont xxx be";
            CHECK(find(text, "dont") == string("dont"));
            CHECK(find(text, "Dont") == string("dont"));
            CHECK(find(text, "DOnt") == string("dont"));
            CHECK(find(text, "DONt") == string("dont"));
            CHECK(find(text, "DONT") == string("dont"));
            CHECK(find(text, "DunT") == string("dont"));
            CHECK(find(text, "DUNT") == string("dont"));
            CHECK(find(text, "TONT") == string("dont"));
            CHECK(find(text, "TONT") == string("dont"));
            CHECK(find(text, "DUND") == string("dont"));
            CHECK(find(text, "Dunt") == string("dont"));
            CHECK(find(text, "BE") == string("be"));
            CHECK(find(text, "be") == string("be"));
            CHECK(find(text, "pe") == string("be"));
            CHECK(find(text, "fe") == string("be"));
            CHECK(find(text, "PE") == string("be"));
            CHECK(find(text, "FE") == string("be"));

}

TEST_CASE("Test for worry") {
    string text = "xxx worry yyy";
            CHECK(find(text, "worry") == string("worry"));
            CHECK(find(text, "WORRY") == string("worry"));
            CHECK(find(text, "WORRY") == string("worry"));
            CHECK(find(text, "Worry") == string("worry"));
            CHECK(find(text, "Vorry") == string("worry"));
            CHECK(find(text, "Vurry") == string("worry"));
            CHECK(find(text, "Vurri") == string("worry"));
            CHECK(find(text, "VurrI") == string("worry"));
            CHECK(find(text, "VorrI") == string("worry"));
            CHECK(find(text, "VORRI") == string("worry"));
            CHECK(find(text, "VORrI") == string("worry"));
}

TEST_CASE("Test for bff") {
    string text = "bff xxx yyy ";
            CHECK(find(text, "bff") == string("bff"));
            CHECK(find(text, "BFF") == string("bff"));
            CHECK(find(text, "Bff") == string("bff"));
            CHECK(find(text, "BFF") == string("bff"));
            CHECK(find(text, "BfF") == string("bff"));
            CHECK(find(text, "fbb") == string("bff"));
            CHECK(find(text, "fBB") == string("bff"));
            CHECK(find(text, "fBb") == string("bff"));
            CHECK(find(text, "fbB") == string("bff"));
            CHECK(find(text, "pbB") == string("bff"));
            CHECK(find(text, "fff") == string("bff"));
            CHECK(find(text, "BBB") == string("bff"));
            CHECK(find(text, "FFF") == string("bff"));
            CHECK(find(text, "BFB") == string("bff"));
            CHECK(find(text, "PPP") == string("bff"));
            CHECK(find(text, "PPP") == string("bff"));
            CHECK(find(text, "ppp") == string("bff"));
            CHECK(find(text, "ppB") == string("bff"));
            CHECK(find(text, "ppB") == string("bff"));
}

TEST_CASE("Test for smile") {
    string text = "smile AAA BBB CCC DDD";
            CHECK(find(text, "zmile") == string("smile"));
            CHECK(find(text, "SMILE") == string("smile"));
            CHECK(find(text, "Smile") == string("smile"));
            CHECK(find(text, "SMilE") == string("smile"));
            CHECK(find(text, "SMile") == string("smile"));
            CHECK(find(text, "SMIle") == string("smile"));
            CHECK(find(text, "ZMILE") == string("smile"));
            CHECK(find(text, "ZmILE") == string("smile"));
            CHECK(find(text, "ZmiLE") == string("smile"));
            CHECK(find(text, "ZmilE") == string("smile"));
            CHECK(find(text, "Zmile") == string("smile"));
            CHECK(find(text, "zmiLe") == string("smile"));
            CHECK(find(text, "zmyLe") == string("smile"));
            CHECK(find(text, "zmYLe") == string("smile"));

}

TEST_CASE("Test for apple") {
    string text = "apple AAA BBB CCC DDD EEE bed boy";
            CHECK(find(text, "apple") == string("apple"));
            CHECK(find(text, "APPLE") == string("apple"));
            CHECK(find(text, "APple") == string("apple"));
            CHECK(find(text, "APple") == string("apple"));
            CHECK(find(text, "APPle") == string("apple"));
            CHECK(find(text, "APPLe") == string("apple"));
            CHECK(find(text, "AFFLE") == string("apple"));
            CHECK(find(text, "AFfLe") == string("apple"));
            CHECK(find(text, "Affle") == string("apple"));
            CHECK(find(text, "Abble") == string("apple"));
            CHECK(find(text, "apble") == string("apple"));
            CHECK(find(text, "APBLE") == string("apple"));
}
TEST_CASE("Test for java") {
    string text = " AAA BBB CCC java DDD EEE bed boy";
            CHECK(find(text, "java") == string("java"));
            CHECK(find(text, "Java") == string("java"));
            CHECK(find(text, "JAva") == string("java"));
            CHECK(find(text, "JAVa") == string("java"));
            CHECK(find(text, "JAVA") == string("java"));
}

TEST_CASE("Test for YOU") {
    string text = " AAA BBB CCC YOU aRe Ediut bed boy";
            CHECK(find(text, "YoU") == string("YOU"));
            CHECK(find(text, "YOU") == string("YOU"));
            CHECK(find(text, "You") == string("YOU"));
            CHECK(find(text, "YOu") == string("YOU"));
            CHECK(find(text, "YOU") == string("YOU"));
            CHECK(find(text, "Iou") == string("YOU"));
            CHECK(find(text, "IOU") == string("YOU"));
            CHECK(find(text, "IoU") == string("YOU"));
            CHECK(find(text, "Ioo") == string("YOU"));
            CHECK(find(text, "IoO") == string("YOU"));
            CHECK(find(text, "IOO") == string("YOU"));
            CHECK(find(text, "iOO") == string("YOU"));
            CHECK(find(text, "iOo") == string("YOU"));
            CHECK(find(text, "iOo") == string("YOU"));
            CHECK(find(text, "YoU") == string("YOU"));
            CHECK(find(text, "YUU") == string("YOU"));
            CHECK(find(text, "YUu") == string("YOU"));

}
