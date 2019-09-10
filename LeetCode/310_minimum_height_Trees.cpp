#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <list>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

class Solution {
    
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges){
        int se = edges.size();
        if(se == 0)
            return vector<int>();
        vector<vector<int>> g(n, vector<int>());
        for(int i = 0; i < se; i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i = 0; i < n; i++){
            cout<<i<<"  :  ";
            for(int j = 0; j < g[i].size(); j++){
                cout<<g[i][j]<<' ';
            }
            cout<<'\n';
        }
        int cur, depth = 0, sst, mindepth = INT_MAX;
        vector<int> re;
        queue
        for(int i = 0; i < n; i++){

        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        int se = edges.size();
        if(se == 0)
            return vector<int>();
        vector<vector<int>> g(n, vector<int>());
        for(int i = 0; i < se; i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i = 0; i < n; i++){
            cout<<i<<"  :  ";
            for(int j = 0; j < g[i].size(); j++){
                cout<<g[i][j]<<' ';
            }
            cout<<'\n';
        }
        int cur, depth = 0, sst, mindepth = INT_MAX;
        vector<int> re;
        for(int i = 0; i < n; i++){
            if(g[i].size() < 5 && n > 1000) continue;
            vector<bool> vis(n, false);
            cout<<"i  ---------------------------------------------------------------------- "<<i<<'\n';
            queue<int> st;
            st.push(i);
            depth = 0;
            while(!st.empty()){
                sst = st.size();
                cout<<" while "<<sst<<'\n';
                for(int i = 0; i < sst; i++){
                    cur = st.front(); st.pop();
                    vis[cur] = true;
                    cout<<"   top "<<cur<<'\n';
                    for(int j = 0; j < g[cur].size(); j++){
                        cout<<"          cur "<<g[cur][j]<<'\n';
                        if(!vis[g[cur][j]])
                            st.push(g[cur][j]);
                        vis[g[cur][j]] = true;
                    }
                }
                depth++;
            }
            cout<<"depth  "<<depth<<' '<<mindepth<<'\n';
            if(depth < mindepth){
                re = vector<int>(1, i);
                mindepth = depth;
            }
            else if(depth == mindepth){
                re.push_back(i);
            }
        }
        return re;
    }   
};

// find longest path and then the middle node
class Solution {
public:
    int max_len;
    int v;
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<vector<int> > graph(n);
        for(int i = 0 ; i < edges.size(); i++){
            graph[edges[i].first].push_back(edges[i].second);
            graph[edges[i].second].push_back(edges[i].first);
        }
        vector<bool> visited(n,false);
        vector<int> path;
         
        dfs(graph,visited,0,0,path);
        
        max_len = 0;
        path.clear();
        dfs(graph,visited,v,0,path);
       
        vector<int> res;
        if(max_len % 2 == 0){
            res.push_back(path[max_len/2]);
            res.push_back(path[max_len/2-1]);
        }
        else{
            res.push_back(path[max_len/2]);
        }
        return res;
    }
    
    void dfs(vector<vector<int> >& graph, vector<bool>& visited, int i, int count, vector<int>& path){
        
        visited[i] = true;
        count++;
        path.push_back(i);
        
        
        for(auto it = graph[i].begin(); it != graph[i].end(); it++){
            if(!visited[*it]){
                dfs(graph,visited,*it,count,path);
            }
        }
        
        if(count > max_len){
            max_len = count;
            v = i;
        }
        visited[i] = false;
    }
};
int main(){
    Solution sol;
    int n = 1919;
    vector<vector<int>>edges{{0,1},{0,2},{2,3},{2,4},{1,5},{5,6},{2,7},{4,8},{5,9},{8,10},{4,11},{0,12},{11,13},{13,14},{10,15},{1,16},{9,17},{12,18},{0,19},{10,20},{18,21},{17,22},{12,23},{15,24},{10,25},{13,26},{10,27},{11,28},{0,29},{22,30},{17,31},{27,32},{24,33},{23,34},{4,35},{20,36},{23,37},{15,38},{37,39},{7,40},{3,41},{28,42},{12,43},{39,44},{40,45},{24,46},{19,47},{21,48},{20,49},{35,50},{43,51},{2,52},{17,53},{14,54},{10,55},{30,56},{3,57},{36,58},{30,59},{13,60},{5,61},{37,62},{31,63},{6,64},{59,65},{52,66},{9,67},{49,68},{11,69},{0,70},{25,71},{30,72},{27,73},{66,74},{33,75},{69,76},{48,77},{13,78},{76,79},{42,80},{16,81},{40,82},{37,83},{77,84},{30,85},{67,86},{50,87},{58,88},{34,89},{7,90},{62,91},{79,92},{20,93},{72,94},{61,95},{41,96},{68,97},{29,98},{33,99},{67,100},{55,101},{28,102},{51,103},{93,104},{82,105},{75,106},{46,107},{81,108},{68,109},{30,110},{95,111},{4,112},{74,113},{32,114},{8,115},{27,116},{10,117},{84,118},{52,119},{16,120},{28,121},{35,122},{16,123},{77,124},{13,125},{34,126},{33,127},{96,128},{21,129},{19,130},{122,131},{83,132},{74,133},{40,134},{57,135},{23,136},{81,137},{7,138},{55,139},{55,140},{55,141},{77,142},{133,143},{135,144},{132,145},{41,146},{46,147},{89,148},{2,149},{98,150},{131,151},{149,152},{86,153},{123,154},{86,155},{80,156},{63,157},{127,158},{80,159},{20,160},{87,161},{121,162},{154,163},{32,164},{46,165},{7,166},{132,167},{2,168},{83,169},{38,170},{28,171},{171,172},{32,173},{148,174},{92,175},{7,176},{176,177},{136,178},{112,179},{110,180},{101,181},{180,182},{149,183},{107,184},{166,185},{120,186},{12,187},{159,188},{26,189},{141,190},{118,191},{146,192},{78,193},{132,194},{101,195},{11,196},{131,197},{141,198},{191,199},{33,200},{1,201},{51,202},{30,203},{14,204},{98,205},{199,206},{187,207},{55,208},{65,209},{101,210},{17,211},{171,212},{62,213},{101,214},{26,215},{71,216},{80,217},{27,218},{37,219},{171,220},{219,221},{181,222},{85,223},{218,224},{112,225},{185,226},{218,227},{110,228},{79,229},{221,230},{77,231},{223,232},{168,233},{20,234},{32,235},{224,236},{37,237},{119,238},{192,239},{221,240},{67,241},{16,242},{20,243},{59,244},{188,245},{127,246},{128,247},{133,248},{93,249},{59,250},{17,251},{119,252},{176,253},{109,254},{76,255},{165,256},{169,257},{125,258},{169,259},{76,260},{114,261},{87,262},{204,263},{250,264},{103,265},{135,266},{151,267},{60,268},{182,269},{105,270},{189,271},{91,272},{133,273},{104,274},{219,275},{191,276},{243,277},{188,278},{275,279},{217,280},{189,281},{118,282},{10,283},{104,284},{61,285},{225,286},{67,287},{156,288},{52,289},{105,290},{146,291},{47,292},{211,293},{178,294},{235,295},{196,296},{108,297},{244,298},{233,299},{222,300},{127,301},{261,302},{254,303},{279,304},{235,305},{159,306},{192,307},{162,308},{167,309},{90,310},{295,311},{198,312},{20,313},{106,314},{283,315},{65,316},{183,317},{291,318},{183,319},{190,320},{118,321},{289,322},{125,323},{267,324},{316,325},{155,326},{229,327},{154,328},{291,329},{312,330},{274,331},{306,332},{252,333},{236,334},{131,335},{3,336},{113,337},{29,338},{126,339},{20,340},{182,341},{326,342},{212,343},{154,344},{156,345},{36,346},{240,347},{162,348},{69,349},{6,350},{60,351},{314,352},{14,353},{63,354},{312,355},{52,356},{252,357},{33,358},{295,359},{328,360},{227,361},{215,362},{261,363},{41,364},{306,365},{250,366},{10,367},{100,368},{120,369},{12,370},{223,371},{274,372},{311,373},{40,374},{344,375},{80,376},{350,377},{225,378},{368,379},{284,380},{237,381},{43,382},{303,383},{101,384},{212,385},{237,386},{331,387},{163,388},{87,389},{91,390},{182,391},{298,392},{80,393},{203,394},{105,395},{3,396},{101,397},{384,398},{273,399},{223,400},{175,401},{142,402},{38,403},{347,404},{160,405},{223,406},{405,407},{83,408},{264,409},{67,410},{357,411},{226,412},{62,413},{45,414},{20,415},{51,416},{374,417},{409,418},{334,419},{348,420},{295,421},{209,422},{356,423},{132,424},{350,425},{83,426},{193,427},{203,428},{172,429},{391,430},{76,431},{214,432},{327,433},{214,434},{360,435},{304,436},{220,437},{115,438},{348,439},{193,440},{438,441},{33,442},{426,443},{228,444},{395,445},{102,446},{238,447},{24,448},{104,449},{431,450},{137,451},{437,452},{52,453},{261,454},{226,455},{50,456},{105,457},{15,458},{295,459},{237,460},{234,461},{422,462},{83,463},{238,464},{276,465},{215,466},{255,467},{268,468},{221,469},{53,470},{282,471},{220,472},{422,473},{40,474},{217,475},{363,476},{412,477},{31,478},{427,479},{72,480},{33,481},{441,482},{355,483},{113,484},{374,485},{354,486},{96,487},{48,488},{241,489},{453,490},{393,491},{230,492},{194,493},{252,494},{164,495},{346,496},{8,497},{109,498},{89,499},{55,500},{200,501},{42,502},{44,503},{465,504},{406,505},{279,506},{305,507},{499,508},{387,509},{245,510},{15,511},{141,512},{73,513},{190,514},{3,515},{73,516},{258,517},{490,518},{16,519},{138,520},{37,521},{470,522},{248,523},{221,524},{446,525},{159,526},{464,527},{512,528},{152,529},{156,530},{526,531},{214,532},{294,533},{216,534},{485,535},{444,536},{74,537},{480,538},{153,539},{510,540},{86,541},{140,542},{533,543},{409,544},{87,545},{78,546},{84,547},{239,548},{82,549},{215,550},{365,551},{315,552},{471,553},{394,554},{55,555},{262,556},{511,557},{175,558},{429,559},{163,560},{541,561},{384,562},{216,563},{384,564},{392,565},{314,566},{486,567},{209,568},{459,569},{475,570},{209,571},{515,572},{515,573},{141,574},{354,575},{353,576},{95,577},{103,578},{338,579},{291,580},{323,581},{315,582},{424,583},{465,584},{482,585},{199,586},{125,587},{438,588},{94,589},{555,590},{229,591},{183,592},{0,593},{211,594},{300,595},{374,596},{439,597},{479,598},{553,599},{468,600},{68,601},{284,602},{312,603},{491,604},{316,605},{353,606},{5,607},{229,608},{299,609},{530,610},{430,611},{47,612},{306,613},{187,614},{63,615},{318,616},{129,617},{84,618},{197,619},{168,620},{442,621},{274,622},{92,623},{479,624},{366,625},{276,626},{371,627},{475,628},{620,629},{250,630},{471,631},{249,632},{39,633},{342,634},{432,635},{548,636},{274,637},{407,638},{0,639},{567,640},{239,641},{569,642},{266,643},{190,644},{482,645},{420,646},{85,647},{535,648},{130,649},{173,650},{452,651},{65,652},{74,653},{401,654},{333,655},{384,656},{304,657},{259,658},{112,659},{483,660},{160,661},{561,662},{469,663},{572,664},{255,665},{613,666},{628,667},{294,668},{266,669},{289,670},{140,671},{621,672},{184,673},{322,674},{334,675},{61,676},{111,677},{451,678},{253,679},{641,680},{482,681},{658,682},{561,683},{324,684},{221,685},{319,686},{589,687},{671,688},{453,689},{374,690},{389,691},{383,692},{644,693},{131,694},{625,695},{64,696},{253,697},{223,698},{643,699},{651,700},{506,701},{641,702},{675,703},{153,704},{551,705},{6,706},{488,707},{126,708},{476,709},{290,710},{276,711},{198,712},{423,713},{473,714},{220,715},{518,716},{316,717},{116,718},{477,719},{206,720},{22,721},{614,722},{147,723},{34,724},{141,725},{503,726},{311,727},{371,728},{277,729},{633,730},{191,731},{106,732},{596,733},{231,734},{128,735},{80,736},{530,737},{539,738},{254,739},{637,740},{629,741},{550,742},{90,743},{235,744},{451,745},{533,746},{446,747},{362,748},{451,749},{181,750},{508,751},{306,752},{305,753},{675,754},{378,755},{41,756},{609,757},{495,758},{685,759},{511,760},{244,761},{587,762},{337,763},{400,764},{682,765},{738,766},{346,767},{422,768},{410,769},{179,770},{743,771},{508,772},{769,773},{374,774},{515,775},{44,776},{473,777},{556,778},{153,779},{124,780},{725,781},{347,782},{512,783},{255,784},{301,785},{562,786},{28,787},{563,788},{578,789},{84,790},{257,791},{698,792},{358,793},{329,794},{759,795},{399,796},{197,797},{202,798},{514,799},{207,800},{609,801},{535,802},{264,803},{718,804},{201,805},{656,806},{196,807},{364,808},{261,809},{380,810},{55,811},{613,812},{120,813},{780,814},{218,815},{745,816},{414,817},{195,818},{481,819},{280,820},{20,821},{651,822},{770,823},{110,824},{248,825},{470,826},{600,827},{15,828},{545,829},{499,830},{670,831},{191,832},{259,833},{399,834},{486,835},{528,836},{311,837},{491,838},{491,839},{465,840},{732,841},{504,842},{296,843},{268,844},{402,845},{763,846},{383,847},{20,848},{153,849},{318,850},{828,851},{649,852},{813,853},{288,854},{529,855},{168,856},{121,857},{660,858},{44,859},{14,860},{738,861},{534,862},{351,863},{426,864},{183,865},{679,866},{624,867},{360,868},{685,869},{450,870},{331,871},{38,872},{115,873},{356,874},{561,875},{85,876},{161,877},{653,878},{740,879},{212,880},{753,881},{358,882},{783,883},{69,884},{185,885},{852,886},{366,887},{828,888},{596,889},{411,890},{45,891},{763,892},{806,893},{666,894},{536,895},{68,896},{38,897},{234,898},{39,899},{30,900},{127,901},{457,902},{707,903},{126,904},{418,905},{208,906},{250,907},{517,908},{625,909},{150,910},{873,911},{556,912},{45,913},{26,914},{122,915},{41,916},{472,917},{274,918},{357,919},{910,920},{169,921},{606,922},{692,923},{291,924},{102,925},{343,926},{2,927},{416,928},{325,929},{440,930},{383,931},{181,932},{598,933},{807,934},{401,935},{911,936},{522,937},{101,938},{286,939},{864,940},{523,941},{500,942},{727,943},{690,944},{937,945},{459,946},{657,947},{568,948},{160,949},{158,950},{114,951},{450,952},{630,953},{513,954},{950,955},{88,956},{798,957},{584,958},{743,959},{20,960},{671,961},{413,962},{126,963},{673,964},{435,965},{639,966},{630,967},{19,968},{926,969},{765,970},{595,971},{944,972},{462,973},{936,974},{182,975},{824,976},{964,977},{620,978},{732,979},{110,980},{1,981},{367,982},{41,983},{652,984},{841,985},{660,986},{343,987},{166,988},{846,989},{438,990},{633,991},{306,992},{958,993},{615,994},{323,995},{139,996},{630,997},{443,998},{524,999},{431,1000},{57,1001},{390,1002},{505,1003},{843,1004},{558,1005},{604,1006},{226,1007},{468,1008},{92,1009},{522,1010},{74,1011},{708,1012},{915,1013},{912,1014},{446,1015},{112,1016},{593,1017},{601,1018},{814,1019},{756,1020},{500,1021},{596,1022},{508,1023},{557,1024},{21,1025},{589,1026},{255,1027},{934,1028},{61,1029},{204,1030},{475,1031},{936,1032},{687,1033},{829,1034},{973,1035},{313,1036},{144,1037},{811,1038},{201,1039},{984,1040},{297,1041},{1004,1042},{198,1043},{70,1044},{565,1045},{349,1046},{893,1047},{705,1048},{449,1049},{203,1050},{228,1051},{278,1052},{945,1053},{913,1054},{680,1055},{992,1056},{587,1057},{33,1058},{435,1059},{578,1060},{30,1061},{793,1062},{780,1063},{856,1064},{322,1065},{842,1066},{446,1067},{449,1068},{12,1069},{663,1070},{157,1071},{1017,1072},{457,1073},{180,1074},{691,1075},{330,1076},{300,1077},{1017,1078},{1033,1079},{357,1080},{337,1081},{72,1082},{71,1083},{65,1084},{842,1085},{23,1086},{849,1087},{727,1088},{193,1089},{125,1090},{211,1091},{356,1092},{44,1093},{1050,1094},{889,1095},{396,1096},{777,1097},{105,1098},{799,1099},{423,1100},{771,1101},{818,1102},{1064,1103},{1003,1104},{1048,1105},{922,1106},{806,1107},{934,1108},{392,1109},{13,1110},{1046,1111},{974,1112},{772,1113},{468,1114},{146,1115},{564,1116},{681,1117},{509,1118},{595,1119},{809,1120},{74,1121},{614,1122},{487,1123},{595,1124},{168,1125},{1032,1126},{86,1127},{808,1128},{864,1129},{1095,1130},{1123,1131},{572,1132},{835,1133},{789,1134},{624,1135},{1106,1136},{725,1137},{1073,1138},{679,1139},{654,1140},{1048,1141},{1077,1142},{546,1143},{530,1144},{558,1145},{452,1146},{946,1147},{115,1148},{112,1149},{1109,1150},{338,1151},{138,1152},{953,1153},{682,1154},{188,1155},{636,1156},{953,1157},{804,1158},{405,1159},{391,1160},{417,1161},{124,1162},{198,1163},{103,1164},{1131,1165},{331,1166},{307,1167},{994,1168},{917,1169},{1016,1170},{60,1171},{13,1172},{591,1173},{970,1174},{817,1175},{291,1176},{482,1177},{948,1178},{802,1179},{979,1180},{906,1181},{948,1182},{1096,1183},{1070,1184},{56,1185},{412,1186},{132,1187},{646,1188},{1024,1189},{213,1190},{972,1191},{1159,1192},{303,1193},{1114,1194},{58,1195},{217,1196},{229,1197},{722,1198},{217,1199},{559,1200},{889,1201},{155,1202},{1020,1203},{563,1204},{819,1205},{593,1206},{546,1207},{134,1208},{778,1209},{506,1210},{641,1211},{823,1212},{720,1213},{195,1214},{1087,1215},{904,1216},{935,1217},{1198,1218},{949,1219},{1158,1220},{570,1221},{57,1222},{627,1223},{1163,1224},{933,1225},{678,1226},{61,1227},{149,1228},{703,1229},{155,1230},{391,1231},{460,1232},{913,1233},{191,1234},{179,1235},{385,1236},{357,1237},{803,1238},{500,1239},{295,1240},{436,1241},{163,1242},{1014,1243},{1040,1244},{11,1245},{488,1246},{225,1247},{14,1248},{1210,1249},{40,1250},{445,1251},{1171,1252},{520,1253},{391,1254},{1249,1255},{830,1256},{571,1257},{944,1258},{1086,1259},{1023,1260},{86,1261},{925,1262},{161,1263},{527,1264},{229,1265},{225,1266},{724,1267},{426,1268},{270,1269},{552,1270},{1223,1271},{1266,1272},{250,1273},{773,1274},{290,1275},{1133,1276},{1070,1277},{1234,1278},{1053,1279},{307,1280},{1184,1281},{394,1282},{973,1283},{829,1284},{130,1285},{26,1286},{680,1287},{894,1288},{514,1289},{714,1290},{643,1291},{212,1292},{1081,1293},{1026,1294},{293,1295},{219,1296},{1275,1297},{22,1298},{1182,1299},{843,1300},{987,1301},{1007,1302},{499,1303},{283,1304},{641,1305},{374,1306},{458,1307},{1119,1308},{85,1309},{298,1310},{924,1311},{1098,1312},{560,1313},{640,1314},{1042,1315},{765,1316},{99,1317},{896,1318},{1206,1319},{341,1320},{891,1321},{342,1322},{152,1323},{615,1324},{438,1325},{135,1326},{289,1327},{563,1328},{752,1329},{550,1330},{807,1331},{666,1332},{1158,1333},{501,1334},{5,1335},{318,1336},{206,1337},{807,1338},{327,1339},{201,1340},{1242,1341},{419,1342},{540,1343},{1000,1344},{272,1345},{135,1346},{1010,1347},{654,1348},{845,1349},{1332,1350},{810,1351},{960,1352},{955,1353},{809,1354},{997,1355},{565,1356},{313,1357},{957,1358},{1129,1359},{940,1360},{1176,1361},{1333,1362},{1288,1363},{154,1364},{94,1365},{484,1366},{3,1367},{302,1368},{1214,1369},{1318,1370},{1274,1371},{667,1372},{411,1373},{481,1374},{303,1375},{66,1376},{791,1377},{1245,1378},{887,1379},{961,1380},{1319,1381},{1355,1382},{1205,1383},{1155,1384},{420,1385},{1313,1386},{934,1387},{1273,1388},{391,1389},{1137,1390},{131,1391},{603,1392},{1215,1393},{331,1394},{850,1395},{1149,1396},{160,1397},{1379,1398},{968,1399},{1145,1400},{1020,1401},{637,1402},{1102,1403},{778,1404},{1386,1405},{1131,1406},{134,1407},{906,1408},{748,1409},{761,1410},{322,1411},{585,1412},{1400,1413},{667,1414},{1201,1415},{402,1416},{1180,1417},{962,1418},{452,1419},{895,1420},{1367,1421},{204,1422},{591,1423},{610,1424},{787,1425},{23,1426},{753,1427},{435,1428},{719,1429},{1193,1430},{1220,1431},{1010,1432},{247,1433},{1088,1434},{1384,1435},{1265,1436},{772,1437},{1130,1438},{332,1439},{1365,1440},{796,1441},{1115,1442},{94,1443},{366,1444},{1419,1445},{327,1446},{809,1447},{1153,1448},{414,1449},{1027,1450},{499,1451},{136,1452},{1314,1453},{640,1454},{746,1455},{358,1456},{394,1457},{1285,1458},{314,1459},{1264,1460},{300,1461},{859,1462},{1248,1463},{332,1464},{697,1465},{50,1466},{124,1467},{172,1468},{42,1469},{730,1470},{1300,1471},{951,1472},{1041,1473},{1433,1474},{574,1475},{1293,1476},{997,1477},{1296,1478},{1251,1479},{332,1480},{605,1481},{1056,1482},{638,1483},{1444,1484},{501,1485},{31,1486},{701,1487},{299,1488},{995,1489},{167,1490},{423,1491},{1465,1492},{439,1493},{987,1494},{1181,1495},{4,1496},{1048,1497},{204,1498},{787,1499},{160,1500},{445,1501},{620,1502},{1315,1503},{580,1504},{1307,1505},{288,1506},{679,1507},{1505,1508},{477,1509},{314,1510},{172,1511},{615,1512},{464,1513},{493,1514},{612,1515},{205,1516},{1306,1517},{332,1518},{37,1519},{421,1520},{1186,1521},{268,1522},{826,1523},{746,1524},{784,1525},{321,1526},{160,1527},{430,1528},{1397,1529},{127,1530},{579,1531},{781,1532},{1125,1533},{85,1534},{976,1535},{1040,1536},{298,1537},{1174,1538},{813,1539},{402,1540},{1061,1541},{982,1542},{157,1543},{1150,1544},{1484,1545},{715,1546},{1267,1547},{565,1548},{1047,1549},{1262,1550},{1527,1551},{1511,1552},{1367,1553},{396,1554},{425,1555},{37,1556},{1215,1557},{974,1558},{901,1559},{431,1560},{654,1561},{1203,1562},{1478,1563},{1357,1564},{810,1565},{1159,1566},{1452,1567},{142,1568},{254,1569},{1529,1570},{1054,1571},{777,1572},{217,1573},{707,1574},{582,1575},{1500,1576},{1404,1577},{206,1578},{135,1579},{900,1580},{1061,1581},{1510,1582},{1507,1583},{39,1584},{646,1585},{1421,1586},{335,1587},{1337,1588},{406,1589},{1349,1590},{430,1591},{1329,1592},{1407,1593},{695,1594},{446,1595},{503,1596},{1344,1597},{1385,1598},{1024,1599},{180,1600},{586,1601},{1177,1602},{1003,1603},{1082,1604},{469,1605},{342,1606},{741,1607},{727,1608},{1489,1609},{1194,1610},{833,1611},{805,1612},{1207,1613},{1231,1614},{209,1615},{232,1616},{1351,1617},{85,1618},{312,1619},{807,1620},{1417,1621},{191,1622},{660,1623},{529,1624},{895,1625},{1188,1626},{90,1627},{1016,1628},{222,1629},{416,1630},{1482,1631},{821,1632},{43,1633},{1221,1634},{343,1635},{272,1636},{866,1637},{275,1638},{561,1639},{1225,1640},{174,1641},{978,1642},{1533,1643},{312,1644},{829,1645},{1541,1646},{968,1647},{1309,1648},{1515,1649},{837,1650},{627,1651},{1341,1652},{1414,1653},{561,1654},{1232,1655},{66,1656},{586,1657},{370,1658},{669,1659},{270,1660},{1036,1661},{1204,1662},{872,1663},{1220,1664},{1238,1665},{223,1666},{496,1667},{1431,1668},{1257,1669},{513,1670},{585,1671},{615,1672},{1639,1673},{544,1674},{215,1675},{1082,1676},{1367,1677},{1300,1678},{1395,1679},{60,1680},{1307,1681},{208,1682},{515,1683},{215,1684},{219,1685},{259,1686},{797,1687},{938,1688},{361,1689},{1525,1690},{545,1691},{197,1692},{1256,1693},{1144,1694},{954,1695},{790,1696},{478,1697},{729,1698},{996,1699},{1343,1700},{881,1701},{756,1702},{757,1703},{1485,1704},{220,1705},{1372,1706},{131,1707},{1258,1708},{244,1709},{723,1710},{1344,1711},{599,1712},{560,1713},{1289,1714},{827,1715},{808,1716},{547,1717},{1182,1718},{878,1719},{1180,1720},{1496,1721},{772,1722},{1407,1723},{1639,1724},{1326,1725},{1373,1726},{992,1727},{1312,1728},{39,1729},{1210,1730},{1522,1731},{689,1732},{822,1733},{55,1734},{314,1735},{504,1736},{744,1737},{1334,1738},{1249,1739},{784,1740},{16,1741},{1720,1742},{925,1743},{787,1744},{1610,1745},{1660,1746},{1621,1747},{508,1748},{814,1749},{971,1750},{709,1751},{827,1752},{486,1753},{262,1754},{555,1755},{1623,1756},{83,1757},{638,1758},{1171,1759},{372,1760},{1398,1761},{1082,1762},{661,1763},{629,1764},{1055,1765},{607,1766},{278,1767},{1234,1768},{635,1769},{1057,1770},{1203,1771},{1245,1772},{918,1773},{963,1774},{1618,1775},{676,1776},{1753,1777},{129,1778},{1700,1779},{1003,1780},{1123,1781},{6,1782},{1149,1783},{517,1784},{340,1785},{621,1786},{895,1787},{882,1788},{130,1789},{47,1790},{1648,1791},{167,1792},{170,1793},{373,1794},{261,1795},{1314,1796},{890,1797},{1636,1798},{240,1799},{1280,1800},{278,1801},{1253,1802},{206,1803},{1072,1804},{650,1805},{524,1806},{877,1807},{1054,1808},{1492,1809},{340,1810},{1597,1811},{406,1812},{340,1813},{686,1814},{1076,1815},{412,1816},{1459,1817},{465,1818},{1225,1819},{378,1820},{498,1821},{991,1822},{1813,1823},{525,1824},{1084,1825},{1016,1826},{380,1827},{948,1828},{200,1829},{1630,1830},{1602,1831},{909,1832},{1422,1833},{314,1834},{1243,1835},{686,1836},{1495,1837},{204,1838},{1319,1839},{773,1840},{560,1841},{480,1842},{1328,1843},{541,1844},{422,1845},{158,1846},{37,1847},{565,1848},{289,1849},{926,1850},{460,1851},{1499,1852},{819,1853},{1187,1854},{107,1855},{314,1856},{88,1857},{1533,1858},{259,1859},{1776,1860},{789,1861},{317,1862},{1451,1863},{1207,1864},{267,1865},{1621,1866},{224,1867},{294,1868},{1198,1869},{430,1870},{1171,1871},{573,1872},{1513,1873},{24,1874},{116,1875},{511,1876},{294,1877},{448,1878},{430,1879},{1213,1880},{1708,1881},{1402,1882},{421,1883},{1727,1884},{902,1885},{1651,1886},{1504,1887},{737,1888},{1719,1889},{356,1890},{756,1891},{721,1892},{488,1893},{93,1894},{150,1895},{137,1896},{384,1897},{1630,1898},{683,1899},{1389,1900},{562,1901},{63,1902},{488,1903},{138,1904},{1820,1905},{1691,1906},{465,1907},{1272,1908},{948,1909},{691,1910},{491,1911},{886,1912},{523,1913},{1801,1914},{418,1915},{1021,1916},{172,1917},{1880,1918}};
    vector<int> re = sol.findMinHeightTrees(n, edges);
    for(int i = 0; i < re.size(); i++){
        cout<<re[i]<<' ';    
    }
}