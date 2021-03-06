#include <gtest/gtest.h>
#include "Scanner.h"
#include "Day19.h"


TEST(Day19, Main) {
    std::stringstream in;
    in << "--- scanner 0 ---\n";
    in << "404,-588,-901\n";
    in << "528,-643,409\n";
    in << "-838,591,734\n";
    in << "390,-675,-793\n";
    in << "-537,-823,-458\n";
    in << "-485,-357,347\n";
    in << "-345,-311,381\n";
    in << "-661,-816,-575\n";
    in << "-876,649,763\n";
    in << "-618,-824,-621\n";
    in << "553,345,-567\n";
    in << "474,580,667\n";
    in << "-447,-329,318\n";
    in << "-584,868,-557\n";
    in << "544,-627,-890\n";
    in << "564,392,-477\n";
    in << "455,729,728\n";
    in << "-892,524,684\n";
    in << "-689,845,-530\n";
    in << "423,-701,434\n";
    in << "7,-33,-71\n";
    in << "630,319,-379\n";
    in << "443,580,662\n";
    in << "-789,900,-551\n";
    in << "459,-707,401\n";
    in << "\n";
    in << "--- scanner 1 ---\n";
    in << "686,422,578\n";
    in << "605,423,415\n";
    in << "515,917,-361\n";
    in << "-336,658,858\n";
    in << "95,138,22\n";
    in << "-476,619,847\n";
    in << "-340,-569,-846\n";
    in << "567,-361,727\n";
    in << "-460,603,-452\n";
    in << "669,-402,600\n";
    in << "729,430,532\n";
    in << "-500,-761,534\n";
    in << "-322,571,750\n";
    in << "-466,-666,-811\n";
    in << "-429,-592,574\n";
    in << "-355,545,-477\n";
    in << "703,-491,-529\n";
    in << "-328,-685,520\n";
    in << "413,935,-424\n";
    in << "-391,539,-444\n";
    in << "586,-435,557\n";
    in << "-364,-763,-893\n";
    in << "807,-499,-711\n";
    in << "755,-354,-619\n";
    in << "553,889,-390\n";
    in << "\n";
    in << "--- scanner 2 ---\n";
    in << "649,640,665\n";
    in << "682,-795,504\n";
    in << "-784,533,-524\n";
    in << "-644,584,-595\n";
    in << "-588,-843,648\n";
    in << "-30,6,44\n";
    in << "-674,560,763\n";
    in << "500,723,-460\n";
    in << "609,671,-379\n";
    in << "-555,-800,653\n";
    in << "-675,-892,-343\n";
    in << "697,-426,-610\n";
    in << "578,704,681\n";
    in << "493,664,-388\n";
    in << "-671,-858,530\n";
    in << "-667,343,800\n";
    in << "571,-461,-707\n";
    in << "-138,-166,112\n";
    in << "-889,563,-600\n";
    in << "646,-828,498\n";
    in << "640,759,510\n";
    in << "-630,509,768\n";
    in << "-681,-892,-333\n";
    in << "673,-379,-804\n";
    in << "-742,-814,-386\n";
    in << "577,-820,562\n";
    in << "\n";
    in << "--- scanner 3 ---\n";
    in << "-589,542,597\n";
    in << "605,-692,669\n";
    in << "-500,565,-823\n";
    in << "-660,373,557\n";
    in << "-458,-679,-417\n";
    in << "-488,449,543\n";
    in << "-626,468,-788\n";
    in << "338,-750,-386\n";
    in << "528,-832,-391\n";
    in << "562,-778,733\n";
    in << "-938,-730,414\n";
    in << "543,643,-506\n";
    in << "-524,371,-870\n";
    in << "407,773,750\n";
    in << "-104,29,83\n";
    in << "378,-903,-323\n";
    in << "-778,-728,485\n";
    in << "426,699,580\n";
    in << "-438,-605,-362\n";
    in << "-469,-447,-387\n";
    in << "509,732,623\n";
    in << "647,635,-688\n";
    in << "-868,-804,481\n";
    in << "614,-800,639\n";
    in << "595,780,-596\n";
    in << "\n";
    in << "--- scanner 4 ---\n";
    in << "727,592,562\n";
    in << "-293,-554,779\n";
    in << "441,611,-461\n";
    in << "-714,465,-776\n";
    in << "-743,427,-804\n";
    in << "-660,-479,-426\n";
    in << "832,-632,460\n";
    in << "927,-485,-438\n";
    in << "408,393,-506\n";
    in << "466,436,-512\n";
    in << "110,16,151\n";
    in << "-258,-428,682\n";
    in << "-393,719,612\n";
    in << "-211,-452,876\n";
    in << "808,-476,-593\n";
    in << "-575,615,604\n";
    in << "-485,667,467\n";
    in << "-680,325,-822\n";
    in << "-627,-443,-432\n";
    in << "872,-547,-609\n";
    in << "833,512,582\n";
    in << "807,604,487\n";
    in << "839,-516,451\n";
    in << "891,-625,532\n";
    in << "-652,-548,-490\n";
    in << "30,-46,-14\n";
    std::vector<Scanner> scanners;
    while(in) {
        scanners.push_back(Scanner(in));
    }
    EXPECT_EQ(scanners.size(), 5);
    auto ret = Scanner::getAllBeacons(scanners);  


    EXPECT_EQ(ret.first.size(), 79);
    EXPECT_EQ(Scanner::getMaxManhattanDistance(ret.second), 3621);

}