#include "Head.hpp"

#include "../../models/ModelNV.hpp"
#include "../../models/shapes/SphereModel.hpp"
#include "../../models/geometries/TriangleGeometry.hpp"
#include "../../models/geometries/ScaleGeometry.hpp"
#include "../SimpleEntity.hpp"

using namespace ExcellentPuppy::Entities;

const GEnv headVertices[] = {
	{ //0
		{0.0, 0.9149143695831299, -0.4035767614841461},
		{0.0, 0.9510565400123596, -0.30901700258255005},
	},
	{ //1
		{0.0, 0.6667073369026184, -0.7452925443649292},
		{0.0, 0.8018636703491211, -0.5357714891433716},
	},
	{ //2
		{0.0, 0.48954740166664124, -0.8719748258590698},
		{0.0, 0.4992935359477997, -0.6956970691680908},
	},
	{ //3
		{0.0, -0.9479659199714661, -0.3182775378227234},
		{0.0, -1.4510565996170044, -2.0891144275665283},
	},
	{ //4
		{0.0, -0.7464827299118042, -0.6653645634651184},
		{0.0, -1.3090170621871948, -2.305166721343994},
	},
	{ //5
		{0.0, 0.9415875673294067, 0.33671072125434875},
		{0.0, 0.9510565400123596, 0.3090176284313202},
	},
	{ //6
		{0.0, 0.7943663001060486, 0.6074098944664001},
		{0.0, 0.80901700258255, 0.5877858996391296},
	},
	{ //7
		{0.0, 0.573503851890564, 0.8191778063774109},
		{0.0, 0.5877852439880371, 0.8090177178382874},
	},
	{ //8
		{0.0, 0.3003021478652954, 0.9538254737854004},
		{0.0, 0.30901697278022766, 0.9510571360588074},
	},
	{ //9
		{0.0, 0.07727286219596863, 0.9970091581344604},
		{0.0, -4.371138828673793e-08, 1.0000005960464478},
	},
	{ //10
		{-0.12997832894325256, -0.9492782354354858, -0.2862025797367096},
		{-0.18163573741912842, -1.4510565996170044, -2.053705930709839},
	},
	{ //11
		{-0.2927945852279663, -0.7699819803237915, -0.5668812990188599},
		{-0.34549176692962646, -1.3090170621871948, -2.233412265777588},
	},
	{ //12
		{-0.6377758383750916, -0.21210363507270813, -0.7404095530509949},
		{-0.4755285382270813, -1.087785243988037, -2.406224012374878},
	},
	{ //13
		{-0.6869106292724609, 0.1431012898683548, -0.712485134601593},
		{-0.3971385359764099, -0.8090170621871948, -2.405363082885742},
	},
	{ //14
		{0.0, 1.0, -0.0},
		{0.0, 1.0, 5.894526111660525e-07},
	},
	{ //15
		{-0.1979125291109085, 0.9415875673294067, 0.27237769961357117},
		{-0.1816357970237732, 0.9510565400123596, 0.25000059604644775},
	},
	{ //16
		{-0.3570055365562439, 0.7943663001060486, 0.491409033536911},
		{-0.3454916477203369, 0.80901700258255, 0.47552886605262756},
	},
	{ //17
		{-0.48149052262306213, 0.573503851890564, 0.6627399325370789},
		{-0.4755285084247589, 0.5877852439880371, 0.6545091271400452},
	},
	{ //18
		{-0.5606250166893005, 0.3003021478652954, 0.7716605067253113},
		{-0.5590171217918396, 0.30901697278022766, 0.7694215178489685},
	},
	{ //19
		{-0.5860164165496826, 0.07727286219596863, 0.8065736889839172},
		{-0.5877853035926819, -4.371138828673793e-08, 0.8090175986289978},
	},
	{ //20
		{-0.6649372577667236, 0.4680928885936737, -0.5819574594497681},
		{-0.336100310087204, -0.5365592837333679, -2.3731439113616943},
	},
	{ //21
		{-0.2639850974082947, -0.9563280344009399, -0.12530900537967682},
		{-0.2938927710056305, -1.4510565996170044, -1.9485207796096802},
	},
	{ //22
		{-0.747337281703949, -0.6214178800582886, -0.23511460423469543},
		{-0.5590173006057739, -1.3090170621871948, -2.0292255878448486},
	},
	{ //23
		{-0.9674367308616638, -0.10547196865081787, -0.2299874871969223},
		{-0.6227197051048279, -1.087785243988037, -1.9702202081680298},
	},
	{ //24
		{-0.32023072242736816, 0.9415875673294067, 0.10403759777545929},
		{-0.29389292001724243, 0.9510565400123596, 0.09549194574356079},
	},
	{ //25
		{-0.6219671964645386, 0.7748954892158508, 0.11236914992332458},
		{-0.5590173006057739, 0.80901700258255, 0.18163610994815826},
	},
	{ //26
		{-0.8139286637306213, 0.5653248429298401, 0.13373211026191711},
		{-0.7694212794303894, 0.5877852439880371, 0.2500004172325134},
	},
	{ //27
		{-0.9309366345405579, 0.31241798400878906, 0.18894009292125702},
		{-0.9045087695121765, 0.30901697278022766, 0.29389312863349915},
	},
	{ //28
		{-0.9704275727272034, 0.07672353088855743, 0.22879727184772491},
		{-0.951056718826294, -4.371138828673793e-08, 0.309017539024353},
	},
	{ //29
		{-0.9427472949028015, 0.03805658221244812, -0.33127841353416443},
		{-0.6604260206222534, -0.8090170621871948, -1.8053168058395386},
	},
	{ //30
		{-0.8837854862213135, 0.3230994641780853, -0.33832818269729614},
		{-0.7020197510719299, -0.49423232674598694, -1.6985929012298584},
	},
	{ //31
		{-0.36210212111473083, 0.922208309173584, -0.1355021893978119},
		{-0.2938929498195648, 0.9510565400123596, -0.09549126029014587},
	},
	{ //32
		{-0.6677144765853882, 0.6624347567558289, -0.3395489454269409},
		{-0.501095712184906, 0.7930880784988403, -0.20497465133666992},
	},
	{ //33
		{-0.7790154814720154, 0.4767906665802002, -0.40714743733406067},
		{-0.6158620715141296, 0.5877852439880371, -0.24999982118606567},
	},
	{ //34
		{-0.8225653767585754, 0.35160374641418457, -0.44688254594802856},
		{-0.7392750978469849, 0.30901697278022766, -0.27382737398147583},
	},
	{ //35
		{-0.9201330542564392, 0.2861415445804596, -0.26725059747695923},
		{-0.8461174368858337, -4.371138828673793e-08, -0.3090168237686157},
	},
	{ //36
		{-0.24344615638256073, 0.9085054993629456, -0.3396099805831909},
		{-0.18163584172725677, 0.9510565400123596, -0.24999994039535522},
	},
	{ //37
		{-0.3792229890823364, 0.6482131481170654, -0.6602679491043091},
		{-0.2586607336997986, 0.7722671627998352, -0.48285090923309326},
	},
	{ //38
		{-0.4747764468193054, 0.33722952008247375, -0.8128910064697266},
		{-0.38860005140304565, 0.5022447109222412, -0.6064081192016602},
	},
	{ //39
		{-0.5772271156311035, 0.5332804322242737, -0.6183355450630188},
		{-0.4720887839794159, 0.22347643971443176, -0.6052700281143188},
	},
	{ //40
		{-0.5345622301101685, 0.748039186000824, -0.39320048689842224},
		{-0.587785542011261, -0.04244779795408249, -1.0447711944580078},
	},
	{ //41
		{0.0, 0.8245185613632202, -0.5658131837844849},
		{0.0, 0.07360467314720154, -1.0682851076126099},
	},
	{ //42
		{0.0, 0.9103060960769653, -0.4139225482940674},
		{0.0, -0.11989724636077881, -1.4037039279937744},
	},
	{ //43
		{0.0, -0.45664846897125244, -0.8896145224571228},
		{0.0, -1.087785243988037, -2.5009682178497314},
	},
	{ //44
		{0.0, -0.22360911965370178, -0.9746696352958679},
		{0.0, -0.8090170621871948, -2.624108076095581},
	},
	{ //45
		{0.0, -0.07727286219596863, 0.9970091581344604},
		{0.0, -0.5000000596046448, 1.0000005960464478},
	},
	{ //46
		{0.0, -0.3003021478652954, 0.9538254737854004},
		{0.0, -0.8090170621871948, 0.9510571360588074},
	},
	{ //47
		{0.0, -0.573503851890564, 0.8191778063774109},
		{0.0, -1.087785243988037, 0.8090177178382874},
	},
	{ //48
		{0.0, -0.7943663001060486, 0.6074098944664001},
		{0.0, -1.3090170621871948, 0.5877858400344849},
	},
	{ //49
		{0.0, -0.9542222619056702, 0.29908138513565063},
		{0.0, -1.4510565996170044, 0.30901744961738586},
	},
	{ //50
		{0.0, -0.999969482421875, -0.0066225165501236916},
		{0.0, -1.5, -0.5257730484008789},
	},
	{ //51
		{-0.5860164165496826, -0.07727286219596863, 0.8065736889839172},
		{-0.5877853035926819, -0.5000000596046448, 0.8090175986289978},
	},
	{ //52
		{-0.5606250166893005, -0.3003021478652954, 0.7716605067253113},
		{-0.5590172410011292, -0.8090170621871948, 0.7694214582443237},
	},
	{ //53
		{-0.48149052262306213, -0.573503851890564, 0.6627399325370789},
		{-0.4755285084247589, -1.087785243988037, 0.6545091271400452},
	},
	{ //54
		{-0.3570055365562439, -0.7943663001060486, 0.491409033536911},
		{-0.3454916179180145, -1.3090170621871948, 0.4755288362503052},
	},
	{ //55
		{-0.17587816715240479, -0.9534592628479004, 0.2448805272579193},
		{-0.18163569271564484, -1.4510565996170044, 0.2500004172325134},
	},
	{ //56
		{-0.8506424427032471, -0.44718772172927856, 0.2763756215572357},
		{-0.951056718826294, -0.5000000596046448, 0.309017539024353},
	},
	{ //57
		{-0.9148533344268799, -0.2934659719467163, 0.2772606611251831},
		{-0.9045088887214661, -0.8090170621871948, 0.2938930094242096},
	},
	{ //58
		{-0.7790765166282654, -0.573503851890564, 0.2531205117702484},
		{-0.7694212794303894, -1.087785243988037, 0.2500004172325134},
	},
	{ //59
		{-0.5776848793029785, -0.7943663001060486, 0.18768882751464844},
		{-0.5590172410011292, -1.3090170621871948, 0.18163608014583588},
	},
	{ //60
		{-0.2948698401451111, -0.9501937627792358, 0.10083315521478653},
		{-0.2938927412033081, -1.4510565996170044, 0.09549186378717422},
	},
	{ //61
		{-0.9511093497276306, 0.23276467621326447, -0.20282600820064545},
		{-0.8257463574409485, -0.4804655611515045, -1.132940411567688},
	},
	{ //62
		{-0.9752799868583679, -0.18659016489982605, -0.11832026392221451},
		{-0.8359100222587585, -0.7808118462562561, -1.0652203559875488},
	},
	{ //63
		{-0.8408459424972534, -0.539567232131958, -0.04226813465356827},
		{-0.7694212794303894, -1.087785243988037, -0.24999983608722687},
	},
	{ //64
		{-0.6113467812538147, -0.791253387928009, -0.012146366760134697},
		{-0.5590173006057739, -1.3090170621871948, -0.18163534998893738},
	},
	{ //65
		{-0.32227545976638794, -0.9466231465339661, -0.0012512588873505592},
		{-0.2938927710056305, -1.4510565996170044, -0.09549122303724289},
	},
	{ //66
		{-0.5341654419898987, 0.7775505781173706, -0.3316751718521118},
		{-0.587785542011261, -0.3127281963825226, -1.5936424732208252},
	},
	{ //67
		{-0.01110873743891716, -0.999847412109375, -0.013183996081352234},
		{-0.18163570761680603, -1.4510565996170044, -1.4907306432724},
	},
	{ //68
		{0.0, 0.9429914355278015, -0.3328043520450592},
		{0.0, -0.33337143063545227, -2.054173707962036},
	},
	{ //69
		{0.0, -0.999786376953125, -0.020447401329874992},
		{0.0, -1.4510565996170044, -1.535874605178833},
	},
	{ //70
		{-0.8506424427032471, -0.44718772172927856, 0.2763756215572357},
		{-0.951056718826294, -0.5000000596046448, 0.309017539024353},
	},
};
const GEtriangle headTriangles[] = {
	{11, 43, 4},
	{5, 14, 15},
	{13, 43, 12},
	{8, 19, 9},
	{6, 15, 16},
	{10, 4, 3},
	{7, 16, 17},
	{21, 11, 10},
	{22, 12, 11},
	{7, 18, 8},
	{23, 13, 12},
	{17, 27, 18},
	{15, 14, 24},
	{29, 20, 13},
	{18, 28, 19},
	{15, 25, 16},
	{17, 25, 26},
	{25, 33, 26},
	{26, 34, 27},
	{24, 14, 31},
	{27, 35, 28},
	{25, 31, 32},
	{19, 45, 9},
	{33, 37, 38},
	{42, 66, 40},
	{34, 38, 39},
	{31, 14, 36},
	{28, 51, 19},
	{35, 39, 40},
	{32, 36, 37},
	{37, 0, 1},
	{37, 2, 38},
	{35, 56, 28},
	{39, 2, 41},
	{36, 14, 0},
	{40, 61, 35},
	{40, 41, 42},
	{64, 21, 65},
	{64, 23, 22},
	{62, 23, 63},
	{67, 21, 10},
	{62, 30, 29},
	{47, 54, 48},
	{48, 55, 49},
	{46, 51, 52},
	{50, 49, 55},
	{46, 53, 47},
	{52, 58, 53},
	{53, 59, 54},
	{54, 60, 55},
	{52, 56, 57},
	{50, 55, 60},
	{50, 60, 65},
	{57, 63, 58},
	{58, 64, 59},
	{59, 65, 60},
	{56, 62, 57},
	{61, 66, 30},
	{50, 65, 67},
	{50, 67, 69},
	{69, 10, 3},
	{20, 30, 66},
	{20, 66, 68},
	{44, 13, 20},
	{11, 12, 43},
	{13, 44, 43},
	{8, 18, 19},
	{6, 5, 15},
	{10, 11, 4},
	{7, 6, 16},
	{21, 22, 11},
	{22, 23, 12},
	{7, 17, 18},
	{23, 29, 13},
	{17, 26, 27},
	{29, 30, 20},
	{18, 27, 28},
	{15, 24, 25},
	{17, 16, 25},
	{25, 32, 33},
	{26, 33, 34},
	{27, 34, 35},
	{25, 24, 31},
	{19, 51, 45},
	{33, 32, 37},
	{42, 68, 66},
	{34, 33, 38},
	{28, 56, 51},
	{35, 34, 39},
	{32, 31, 36},
	{37, 36, 0},
	{37, 1, 2},
	{35, 61, 56},
	{39, 38, 2},
	{40, 66, 61},
	{40, 39, 41},
	{64, 22, 21},
	{64, 63, 23},
	{62, 29, 23},
	{67, 65, 21},
	{62, 61, 30},
	{47, 53, 54},
	{48, 54, 55},
	{46, 45, 51},
	{46, 52, 53},
	{52, 57, 58},
	{53, 58, 59},
	{54, 59, 60},
	{52, 51, 56},
	{57, 62, 63},
	{58, 63, 64},
	{59, 64, 65},
	{56, 61, 62},
	{69, 67, 10},
};
const GEnv noseVertices[] = {
	{ //0
		{-0.00079348124563694, 0.8448134064674377, -0.5350505113601685},
		{0.0, 0.27952274680137634, -0.2967965304851532},
	},
	{ //1
		{-0.00027466658502817154, 0.7066866159439087, -0.7075105905532837},
		{0.0, 0.22218193113803864, -0.35062819719314575},
	},
	{ //2
		{-0.00027466658502817154, 0.5193029642105103, -0.8545793294906616},
		{0.0, 0.1422150880098343, -0.41554027795791626},
	},
	{ //3
		{-0.0002441480755805969, 0.16049684584140778, -0.9870296120643616},
		{0.0, -0.28851836919784546, -0.5978837013244629},
	},
	{ //4
		{-0.0002441480755805969, -0.046418651938438416, -0.9989013075828552},
		{0.0, -0.5764707922935486, -0.5966323614120483},
	},
	{ //5
		{-6.103701889514923e-05, 0.9865413308143616, 0.16342662274837494},
		{0.0, 0.2793642282485962, 0.2828868329524994},
	},
	{ //6
		{-6.103701889514923e-05, 0.9638660550117493, 0.26633504033088684},
		{0.0, 0.20992837846279144, 0.596746027469635},
	},
	{ //7
		{-3.0518509447574615e-05, 0.9544664025306702, 0.29828789830207825},
		{0.0, 0.12388496100902557, 0.8720541000366211},
	},
	{ //8
		{-9.155552834272385e-05, 0.99981689453125, -0.018036440014839172},
		{0.0, 0.30504488945007324, -0.038145631551742554},
	},
	{ //9
		{-0.11453596502542496, 0.9846796989440918, 0.13126011192798615},
		{-0.15846693515777588, 0.2793642282485962, 0.22386981546878815},
	},
	{ //10
		{-0.23651844263076782, 0.9477522969245911, 0.2139957845211029},
		{-0.3014218807220459, 0.20992837846279144, 0.48448893427848816},
	},
	{ //11
		{-0.4109012186527252, 0.8901028633117676, 0.19699697196483612},
		{-0.41487157344818115, 0.12388502061367035, 0.7175456881523132},
	},
	{ //12
		{-0.7577135562896729, 0.6122928261756897, 0.22571489214897156},
		{-0.4877108037471771, 0.05369069427251816, 0.8406013250350952},
	},
	{ //13
		{-0.7032074928283691, -0.6014587879180908, 0.3790704011917114},
		{-0.5128094553947449, -7.450580596923828e-08, 0.7089129686355591},
	},
	{ //14
		{-0.27982422709465027, 0.9596239924430847, -0.0277718435972929},
		{-0.25640490651130676, 0.2793642282485962, 0.06936118006706238},
	},
	{ //15
		{-0.5598620772361755, 0.8243049383163452, -0.08401745557785034},
		{-0.4877108335494995, 0.20992843806743622, 0.19059623777866364},
	},
	{ //16
		{-0.7394940257072449, 0.6712851524353027, -0.04995879903435707},
		{-0.632426917552948, 0.0844985693693161, 0.2805820405483246},
	},
	{ //17
		{-0.9871821999549866, 0.07470931112766266, 0.14084291458129883},
		{-0.7118822932243347, -0.024627484381198883, 0.30053767561912537},
	},
	{ //18
		{-0.9788201451301575, 0.10391552746295929, -0.17627491056919098},
		{-0.6837870478630066, -0.15054160356521606, 0.15117734670639038},
	},
	{ //19
		{-0.9666127562522888, -0.029908139258623123, -0.2544328272342682},
		{-0.7837458848953247, -0.334094762802124, 0.19136252999305725},
	},
	{ //20
		{-0.8603472709655762, -0.5090182423591614, -0.026337474584579468},
		{-0.5685803890228271, -0.6919008493423462, 0.16420744359493256},
	},
	{ //21
		{-0.3794060945510864, 0.9139072895050049, -0.14413891732692719},
		{-0.237441286444664, 0.2793642282485962, -0.08189217746257782},
	},
	{ //22
		{-0.7594836354255676, 0.5554063320159912, -0.33866390585899353},
		{-0.40949922800064087, 0.14719797670841217, -0.07786046713590622},
	},
	{ //23
		{-0.9004791378974915, 0.016266364604234695, -0.4345225393772125},
		{-0.6814665198326111, -0.3825523853302002, -0.19146139919757843},
	},
	{ //24
		{-0.860713541507721, -0.3158970773220062, -0.39918211102485657},
		{-0.644340991973877, -0.5856507420539856, -0.22818003594875336},
	},
	{ //25
		{-0.7539292573928833, -0.5441755652427673, -0.36796167492866516},
		{-0.4877108037471771, -0.8090168833732605, -0.18163540959358215},
	},
	{ //26
		{-0.18137149512767792, 0.9423810243606567, -0.28104496002197266},
		{-0.10853106528520584, 0.27936428785324097, -0.22330784797668457},
	},
	{ //27
		{-0.39139989018440247, 0.7389446496963501, -0.5483871102333069},
		{-0.2097804844379425, 0.2144559621810913, -0.3078862726688385},
	},
	{ //28
		{-0.4521927535533905, 0.4832911193370819, -0.7496261596679688},
		{-0.3258807361125946, -0.13599278032779694, -0.4221268892288208},
	},
	{ //29
		{-0.4861293435096741, 0.10666219145059586, -0.8673055171966553},
		{-0.325696736574173, -0.35445544123649597, -0.49242308735847473},
	},
	{ //30
		{-0.5069429874420166, -0.17221595346927643, -0.844569206237793},
		{-0.3035280704498291, -0.5864162445068359, -0.49163365364074707},
	},
	{ //31
		{-0.5670338869094849, -0.2705771028995514, -0.7779473066329956},
		{-0.24258467555046082, -0.8090168833732605, -0.4586332440376282},
	},
	{ //32
		{-0.00030518509447574615, 0.3564867079257965, -0.9342631101608276},
		{0.0, -0.14300060272216797, -0.5528070330619812},
	},
	{ //33
		{-0.0003662221133708954, -0.14886929094791412, -0.9888302087783813},
		{0.0, -0.7526455521583557, -0.5828003883361816},
	},
	{ //34
		{-0.7697073221206665, 0.42313912510871887, -0.4779503643512726},
		{-0.6005527377128601, -0.118116095662117, -0.1939462125301361},
	},
	{ //35
		{-0.7285683751106262, 0.6044190526008606, -0.32218390703201294},
		{-0.43305400013923645, 0.03268417716026306, -0.11370106041431427},
	},
	{ //36
		{-0.5101779103279114, 0.2544633448123932, -0.8215277791023254},
		{-0.28188690543174744, 0.10098766535520554, -0.3641289472579956},
	},
	{ //37
		{-0.5127109289169312, 0.3015533983707428, -0.8038270473480225},
		{-0.38245946168899536, 0.02690018154680729, -0.3296501040458679},
	},
	{ //38
		{-0.4597918689250946, 0.4442579448223114, -0.7688833475112915},
		{-0.15513448417186737, -0.05385871231555939, -0.4555349349975586},
	},
	{ //39
		{-0.00045777764171361923, 0.4123966097831726, -0.9109774827957153},
		{0.0, 0.0025749399792402983, -0.48027729988098145},
	},
	{ //40
		{-0.598834216594696, 0.061464279890060425, -0.7984862923622131},
		{-0.49969983100891113, -0.057507678866386414, -0.27381405234336853},
	},
	{ //41
		{-0.286751925945282, 0.18005920946598053, -0.9409161806106567},
		{-0.37267521023750305, -0.049542173743247986, -0.30533891916275024},
	},
	{ //42
		{-0.39347514510154724, 0.2703329622745514, -0.8786584138870239},
		{-0.13830231130123138, 0.06376751512289047, -0.4176161587238312},
	},
	{ //43
		{-0.4465163052082062, 0.24286629259586334, -0.861171305179596},
		{-0.22947414219379425, -0.031232377514243126, -0.31580016016960144},
	},
};
const GEtriangle noseTriangles[] = {
	{5, 8, 9},
	{5, 10, 6},
	{6, 11, 7},
	{10, 16, 11},
	{11, 17, 12},
	{9, 8, 14},
	{13, 17, 18},
	{9, 15, 10},
	{14, 22, 15},
	{18, 23, 19},
	{15, 35, 16},
	{20, 23, 24},
	{17, 35, 40},
	{14, 8, 21},
	{17, 34, 18},
	{21, 27, 22},
	{34, 29, 23},
	{22, 36, 35},
	{24, 29, 30},
	{21, 8, 26},
	{25, 30, 31},
	{26, 8, 0},
	{30, 33, 31},
	{26, 1, 27},
	{29, 32, 3},
	{27, 2, 36},
	{29, 4, 30},
	{34, 40, 41},
	{28, 34, 41},
	{35, 36, 37},
	{39, 32, 38},
	{32, 28, 38},
	{36, 2, 42},
	{2, 39, 42},
	{28, 43, 38},
	{43, 36, 42},
	{28, 41, 43},
	{37, 36, 43},
	{38, 43, 42},
	{38, 42, 39},
	{40, 37, 41},
	{37, 40, 35},
	{43, 41, 37},
	{5, 9, 10},
	{6, 10, 11},
	{10, 15, 16},
	{11, 16, 17},
	{13, 12, 17},
	{9, 14, 15},
	{14, 21, 22},
	{18, 34, 23},
	{15, 22, 35},
	{20, 19, 23},
	{17, 16, 35},
	{20, 24, 25},
	{17, 40, 34},
	{21, 26, 27},
	{34, 28, 29},
	{22, 27, 36},
	{24, 23, 29},
	{25, 24, 30},
	{30, 4, 33},
	{26, 0, 1},
	{29, 28, 32},
	{27, 1, 2},
	{29, 3, 4},
};
const GEnv earVertices[] = {
	{ //0
		{-0.6477859020233154, 0.599047839641571, 0.47062593698501587},
		{-0.5590171217918396, 0.30901697278022766, 0.7694215178489685},
	},
	{ //1
		{-0.7523728013038635, 0.6436048746109009, 0.14032410085201263},
		{-0.9045087695121765, 0.30901697278022766, 0.29389312863349915},
	},
	{ //2
		{-0.7618335485458374, 0.6188848614692688, -0.191167950630188},
		{-0.7392750978469849, 0.30901697278022766, -0.27382737398147583},
	},
	{ //3
		{-0.8311411142349243, 0.5162510871887207, -0.206488236784935},
		{-0.9974762201309204, -0.00020453333854675293, -0.24593663215637207},
	},
	{ //4
		{-0.8300119042396545, 0.5435041189193726, 0.12503433227539062},
		{-1.1627099514007568, -0.00020453333854675293, 0.3217838704586029},
	},
	{ //5
		{-0.6884059906005859, 0.5500046014785767, 0.47282326221466064},
		{-0.7482845187187195, -0.02541862055659294, 0.93459552526474},
	},
	{ //6
		{-0.8332774043083191, 0.5263221859931946, -0.16913357377052307},
		{-0.9190301299095154, 0.035910606384277344, -0.5200232267379761},
	},
	{ //7
		{-0.8850062489509583, 0.383007287979126, -0.26456496119499207},
		{-1.138567328453064, -0.27932775020599365, -0.20250597596168518},
	},
	{ //8
		{-0.8881191611289978, 0.4369334876537323, 0.1424604058265686},
		{-1.3038010597229004, -0.27932775020599365, 0.3652145266532898},
	},
	{ //9
		{-0.7532883882522583, 0.44129765033721924, 0.48762473464012146},
		{-0.8608691692352295, -0.27932775020599365, 1.0494506359100342},
	},
	{ //10
		{-0.9171727895736694, 0.3331095278263092, -0.21860408782958984},
		{-1.0601211786270142, -0.24321261048316956, -0.4765925705432892},
	},
	{ //11
		{-0.9343546628952026, 0.17563402652740479, -0.3100375235080719},
		{-1.2468785047531128, -0.49055615067481995, -0.17590905725955963},
	},
	{ //12
		{-0.9688100814819336, 0.20422986149787903, 0.14023254811763763},
		{-1.393410086631775, -0.49055615067481995, 0.39181143045425415},
	},
	{ //13
		{-0.8218329548835754, 0.19949950277805328, 0.5336466431617737},
		{-0.9504063129425049, -0.5409843325614929, 1.095526933670044},
	},
	{ //14
		{-0.921720027923584, 0.16946928203105927, -0.3488265573978424},
		{-1.1147021055221558, -0.4884359836578369, -0.47622185945510864},
	},
	{ //15
		{-0.9602649211883545, -0.06842249631881714, -0.2705160677433014},
		{-1.2302873134613037, -0.8526619672775269, -0.13031435012817383},
	},
	{ //16
		{-0.9837031364440918, 0.0236823633313179, 0.17807550728321075},
		{-1.3955211639404297, -0.8526619672775269, 0.43740615248680115},
	},
	{ //17
		{-0.8366954326629639, 0.04199346899986267, 0.5460066795349121},
		{-0.9413976669311523, -0.8778760433197021, 1.1352468729019165},
	},
	{ //18
		{-0.939909040927887, -0.036103397607803345, -0.3394268751144409},
		{-1.151841163635254, -0.8165467977523804, -0.40440094470977783},
	},
};
const GEtriangle earTriangles[] = {
	{1, 4, 5},
	{1, 2, 3},
	{2, 6, 3},
	{3, 6, 10},
	{4, 3, 7},
	{5, 4, 8},
	{7, 10, 14},
	{8, 7, 11},
	{8, 12, 13},
	{11, 14, 18},
	{12, 11, 15},
	{13, 12, 16},
	{1, 5, 0},
	{1, 3, 4},
	{3, 10, 7},
	{4, 7, 8},
	{5, 8, 9},
	{7, 14, 11},
	{8, 11, 12},
	{8, 13, 9},
	{11, 18, 15},
	{12, 15, 16},
	{13, 16, 17},
};

Head::Head(Modeling::Material* dogMaterial,
		Modeling::Material* noseMaterial,
		Modeling::Material* eyeMaterial,
		Modeling::Material* tongueMaterial,
		const GEvector& position,
		const GEvector& rotation,
		const GEvector& scaling) :
			CompositeEntity({}, position, rotation, scaling) {
	auto halfHeadGeometry = new Modeling::TriangleGeometry(headTriangles, sizeof(headTriangles)/sizeof(GEtriangle));
	auto reverseHeadGeometry = new Modeling::ScaleGeometry(halfHeadGeometry, {-1, 1 ,1}, true);
	auto headModel = new Modeling::ModelNV(headVertices, {halfHeadGeometry, reverseHeadGeometry});
	headModel->setMaterial(dogMaterial);
	auto headEntity = new SimpleEntity(headModel, {}, {}, {HEAD_SCALE, HEAD_SCALE, HEAD_SCALE});
	getEntities().push_back(headEntity);
	getDependents()->insert(halfHeadGeometry);
	getDependents()->insert(reverseHeadGeometry);
	getDependents()->insert(headModel);
	getDependents()->insert(headEntity);

	auto halfNoseGeometry = new Modeling::TriangleGeometry(noseTriangles, sizeof(noseTriangles)/sizeof(GEtriangle));
	auto reverseNoseGeometry = new Modeling::ScaleGeometry(halfNoseGeometry, {-1, 1 ,1}, true);
	auto noseModel = new Modeling::ModelNV(noseVertices, {halfNoseGeometry, reverseNoseGeometry});
	noseModel->setMaterial(noseMaterial);
	auto noseEntity = new SimpleEntity(noseModel, {}, {}, {NOSE_SCALE, NOSE_SCALE, NOSE_SCALE});
	noseEntity->setPosition((GEvector){0.0, -0.4230262041091919, -2.3275914192199707} * HEAD_SCALE);
	getEntities().push_back(noseEntity);
	getEntities().push_back(headEntity);
	getDependents()->insert(halfNoseGeometry);
	getDependents()->insert(reverseNoseGeometry);
	getDependents()->insert(noseModel);
	getDependents()->insert(noseEntity);

	auto halfEarGeometry = new Modeling::TriangleGeometry(earTriangles, sizeof(earTriangles)/sizeof(GEtriangle));
	auto reverseEarGeometry = new Modeling::ScaleGeometry(halfEarGeometry, {-1, 1 ,1}, true);
	auto earModel = new Modeling::ModelNV(earVertices, {halfEarGeometry, reverseEarGeometry});
	earModel->setMaterial(dogMaterial);
	auto earEntity = new SimpleEntity(earModel, {}, {}, {HEAD_SCALE, HEAD_SCALE, HEAD_SCALE});
	getEntities().push_back(earEntity);
	getDependents()->insert(halfEarGeometry);
	getDependents()->insert(reverseEarGeometry);
	getDependents()->insert(earModel);
	getDependents()->insert(earEntity);

	auto eyeModel = Modeling::SphereModel::generate(360, 180, 10, 20);
	eyeModel->setMaterial(eyeMaterial);
	auto leftEye = new SimpleEntity(eyeModel, (GEvector){-0.4, 0.3, -0.4}*HEAD_SCALE, {}, (GEvector){0.4, 0.4, 0.2}*HEAD_SCALE);
	getEntities().push_back(leftEye);
	auto rightEye = new SimpleEntity(eyeModel, (GEvector){0.4, 0.3, -0.4}*HEAD_SCALE, {}, (GEvector){0.4, 0.4, 0.2}*HEAD_SCALE);
	getEntities().push_back(rightEye);
	getDependents()->insert(eyeModel);
	getDependents()->insert(leftEye);
	getDependents()->insert(rightEye);
}
Head::~Head() { }
