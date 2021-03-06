#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/longest-string-chain/

class LongestStringChain
{
public:
	// 87 ms, faster than 83.89% : 13 MB, less than 94.23%
	int solution(vector<string> words) {
		size_t sz = words.size();
		sort(begin(words), end(words), [](auto& a, auto& b) { return a.size() < b.size(); });
		//Printer::print(words);

		vector<int> mx(sz, 1);
		//vector<int> cnt(sz, 1);
		int ans = 1;

		map<string, vector<string>> mp;

		for (size_t i = 0; i < sz; i++)
		{
			for (size_t j = 0; j < i; j++)
			{
				//Printer::print(words[j], words[i], isInc(words[j], words[i]));
				if (!isInc(words[j], words[i])) continue;
				mp[words[i]].push_back(words[j]);
				if (mx[j] >= mx[i])
					mx[i] = mx[j] + 1;
				//	, cnt[i] = cnt[j];
				//else if (mx[j] + 1 == mx[i])
				//	cnt[i] += cnt[j];
			}
			ans = max(ans, mx[i]);
		}
		Printer::print(mx);
		//Printer::print(mp);

		//int best = 0;
		//curse(mp, "bdxjpstvlxktytxs", best);
		//string s = "vs", s2 = "xss";
		//Printer::print(isInc(s, s2));

		return ans;
	}
	void curse(map<string, vector<string>>& mp, string key, int& mx) {
		mx++;
		Printer::print(key, mx);
		for (auto a : mp[key])
			curse(mp, a, mx);
	}
	bool isInc(string& a, string& b) {
		if (a.size() + 1 != b.size()) return false;
		int skip = 0;
		for (size_t i = 0; i < a.size(); i++)
		{
			if (a[i] != b[i + skip])
				if (skip)
					return false;
				else
					skip++, i--;
		}
		return skip ? a[a.size() - 1] == b[b.size() - 1] : true;
	}
	vector<int> output = {
		4,
		5,
		1,
		15
	};
	static constexpr int const& inputs = 1;
	vector<vector<string>> input1 = {
		{"a","b","ba","bca","bda","bdca"},
		{"xbc","pcxbcf","xb","cxbc","pcxbc","r"},
		{"abcd","dbqca"},
		{"uiykgmcc","jrgbss","mhkqodcpy","lkj","bwqktun","s","nrctyzifwytjblwy","wrp","scqlcwmxw","irqvnxdcxoejuu","gmlckvofwyifmrw","wbzbyrcppaljigvo","lk","kfeouqyyrer","efzzpvi","ubkcitcmwxk","txihn","mdwdmbtx","vuzvcoaif","jwmboqvhpqodsj","wscfvrfl","pzye","waxyoxftvrgqmkg","wwdidopozinxxn","dclpg","xjsvlxktxs","ajj","pvsdastm","tatjxhygidhn","feafycxdxagn","irqvnxxoeuu","kwjo","tztoovsyfwz","prllrw","sclmx","bbmjnwaxcwaml","gl","wiax","uzvcoaif","ztovyfwz","qxy","zuexoxyp","qxyyrl","pvsdasvtm","femafycxdxaagn","rspvccjcm","wvyiax","vst","efzi","fjmdcc","icsinrbpql","ctybiizlcr","ntyzfwytjblw","tatjxhygidhpn","e","kykizdandafusu","pnepuwcsxl","kfeuqyyrer","afplzhbqguu","hvajtj","prll","ildzdimea","zueoxp","ezi","lqr","jkaagljikwamaqvf","mlzwhkxsn","rspvccbcjjtcm","wscfvrl","m","msygukwlkrqboc","pifojogoveub","bkcmwx","jercgybhss","wrpi","aicsinkgrbpqli","aplzbuu","sclcmxw","atpepgsz","govrcuuglaer","bdxjpsvlxkytxs","uikgm","bm","wvyhiqax","znvaasgfvqi","hatpepgsz","hrzebpa","bnfz","lybtqrfzw","taxhygihn","bjnfzk","mhqp","ide","znvcaasgfvqi","ftv","afplzhbqsguuu","thn","pdbccbe","mxevopfoimgjww","fjmdrcce","rspvccjjcm","jv","motnfwohwule","xjsvlxtxs","bqeb","eug","jftavwgl","rzebpa","lybtqrfazw","zuexoxp","jercgybhsys","hajtj","bkcitcmwxk","mbpvxsdastvtm","mowlznwhkxsn","dvenn","rsacxe","tatjxhygihn","cotybiizlcr","bbmnaxaml","pkwrpsi","nqpdbccbkxens","mbpbovxsdastvtm","mj","pxpsvikwekuq","qeug","dmelddga","aicsinkgrbpxqli","bdxjpsvlxktytxs","pkrllrxw","jkgljikwmaqf","iddie","ctybiizcr","nyzfwytjblw","yvuhmiuehspi","keuqre","wzbypaigvo","sck","uzcoaf","dlpg","ubkcpitlscmwxk","molzwhkxsn","pepuwcsxl","laplm","dclpgc","mahkxqodcpy","sclcmx","hvrzebpaz","bgovrcuuglaer","clazpulmw","yvuyhmiuehspiq","wzbycpaljigvo","sceqalciwmxw","hjytflmvsgv","u","hjyvxytfflhmvsgv","jkgjikwmaqf","fefycxdxagn","ftvw","ofncgxrkqvcr","spvcjc","pvsdastvtm","kykzdandaus","wbzbycppaljigvo","haytpepgsz","jmowlznwhkxsn","aplzhbguu","zvyz","nfvqi","jfvtavwsgl","xejnllhfulns","zhhvbiqiw","jkgljikwmaqvf","tyizc","irqvnxcxoejuu","clvazzpulmw","oncgxrqvcr","qlupvpdkhrm","mtnfwohwule","wwdidopzozinxxn","auiykgmcc","wscfvrfyl","pfksmrullrxw","jwmoqvhpqods","ftavwg","iddiea","kcmw","ykkwjwo","pe","aplzbguu","eu","bbmnaxal","ntyswtnlab","zhhhvbhbiqiw","jwmoqvpqods","kykzdndaus","bbmjnaxcwaml","zunvcaasgfvqi","icsingrbpql","sceqalciwmsxyw","yvuhmiuehsp","bxjsvlxktxs","waxoxftvrgqmkg","cogxxpaknks","scllvazzpulmw","tatjxhygeidhpn","ftvwg","tyz","nafvqi","oby","pgzpkhqog","irqvnxxoejuu","oxwpkxlakcp","bnf","oxwnpkxlakcp","bwqktu","ufybbaozoqk","ntydswtnlab","zvyfz","znaafvqi","npdbccbke","mhkqocpy","kuq","bjnfz","taxhyihn","kwrpsi","qifepmcatbdjlf","lzwhks","kfeuqre","mxevopfoimgww","spvcjcm","oncgxrkqvcr","jftavwsgl","soifcbya","jpzyeg","jwmboqvhpqods","lapulm","jrgbhss","xejfnllhfulns","zhhhvbbiqiw","km","kuqre","scxlzlvazzpulmw","ztvyfwz","wbzbycpaljigvo","rzbpa","vsastm","uybaooqk","dn","ykwjwo","ufybmvbaozoqk","nknm","mbpvsdastvtm","dpgzpxykhqog","wzbypajigvo","bnjnfzk","eollbigtftpdrd","zhbiqiw","yvuhiuehp","zhhhvbhbiqiwg","pfksrullrxw","pzyeg","aplzhbqguu","z","hvrzecbpazw","clvazpulmw","tajxhygihn","pgzpxykhqog","fefyxdxagn","wimomuvhn","lqrzw","xejnlhfulns","jhrc","xsxxs","slmx","jrgss","uikgmc","ncgqvcr","womuhn","aryouvtnmme","uzco","zhhhvbiqiw","hjytflhmvsgv","znvaasfvqi","kuqr","ojrpp","ztoovyfwz","zvz","pxpsviweuq","ufybaooqk","xy","jfvvtavwksvgl","raiachv","bmnaxl","rspvccjjtcm","pgzpxkhqog","xhbtfnqebaj","sceqalciwmsxw","jssctk","uzvcoaf","fefydxagn","jhrvc","mbj","raiahv","nrtyzifwytjblwy","mhqcp","jkgjkwmaqf","wscfvrfylhi","lqrz","ahabucermswyrvl","wxoxftvrgqmkg","ku","uyaoq","mhqocp","ykwjo","vstm","ofncgxrkqvcwr","dqvh","taxyihn","idie","bwqtu","tztoovyfwz","rspvcccjjtcm","uojrpp","wmomuhn","cotycbiizlxcr","nrtyzfwytjblw","ocbya","sceqlciwmxw","ajtj","rspvccbcjjthcm","kfeuqyyre","dmelddg","txyihn","ubkcitlscmwxk","ntyswtnla","bdxjpstvlxktytxs","odqdvbh","pxpsvikeewekuq","mdwdmbdtux","vs","bma","wzbypigvo","qxyy","vsstm","hbtnqeba","hrzebpaz","xhbtfnjsqebbaj","ahaucermswyrv","ddmbtx","zhhbiqiw","pxpsvikewekuq","odqdvgbh","bxjpsvlxktxs","jsck","fjmdc","mdwdmbdtx","jqxyyrl","pxpsvikweuq","ctybizcr","dqvbh","lpl","lqrfzw","ufybaozoqk","znvaafvqi","yvuhmiuehp","hvrzebpazw","pfksrllrxw","alzuu","xjsvxtxs","afplzhbqguuu","icsingrbpqli","hjxytflhmvsgv","femafycxdxagn","uyaoqk","gmlckvofwyifrw","cinrbpql","jrcgbhss","oxwpkxlkcp","jkagljikwamaqvf","eollbigtftpdrdy","rspvcjcm","socbya","clapulm","qeb","kwrpi","efzpi","hbtfnqebaj","kykizdnandafusu","sclvazzpulmw","efzzpvvi","jfvvtavwsvgl","mhqocpy","v","mbpbvxsdastvtm","irqvnxouu","hvaajtj","ofnlcgxrkqvcwr","hbtqeba","hbtqeb","jwmqpds","ntrnlhujdslco","zv","npdbccbken","mhp","ddb","prllw","mddmbtx","clazpulm","cogxxpaknkse","bkitcmwxk","oxwpklkcp","tyiz","jwmqvpqods","waxyoxftvrgqmkgb","afplzhbbqsgujuu","bwtu","jercgbhss","rsacx","mahkqodcpy","cotycbiizlcr","ahabucermswyrv","lupvpkhr","dvnn","b","atpepsz","ncgxqvcr","qe","ubkcitlcmwxk","lyqrfzw","wimomuhn","bbmnaxl","motnfwohrwule","yvuyhmiuehspi","jfvvtavwsgl","rac","fefdxagn","bwqkctun","uotjrpp","ddbtx","afplzhbbqsguuu","xss","xsxs","wvyiqax","kykizdandaus","npdbccbkens","r","oxwnpkxjlakcp","tzmteoovsyfwz","kykizdnandafuspu","ahabulcermswyrvl","xjsxxs","qxyyr","ck","xhbtfnqebbaj","nqpdbccbkens","mpvsdastvtm","zuexqoxyp","gmlkvofwyifrw","kmw","txhn","kykizdandausu","molznwhkxsn","lupvpdkhr","jwmqvpds","bktcmwx","wyiax","hzvaajtj","ddbx","pifojogveub","naafvqi","motnfwjohrwule","odqvbh","aicsingrbpqli","jopzyeg","lybtqrfazrw","pijogveub","xzejfnllhfulns","scxllvazzpulmw","irqyvnxdcxfoejuu","cogxpaknks","pdkwrpsi","wzbycpajigvo","xjsxtxs","irqvnxdcxfoejuu","xhbtfnjqebbaj","uybaoqk","oncgxqvcr","aj","pepuwsxl","lytqrfzw","nkm","jrgs","pkrllrw","wscfvrfyli","bbmjnaxcaml","jftavwg","vuzvcozaif","pifjogveub","cmogxxpaknkse","cinrbql","scqlciwmxw","ztvyfz","mxyevopfoimgjpww","soicbya","lupvpdkhrm","ahaucermsyrv","ufybmvbaouzoqk","bdxjpsvlxktxs","hjxytfflhmvsgv","hjvxytfflhmvsgv","nqpdbccbzkxens","wr","kykzdndus","iddimea","fjmdrcc","efzzpi","vsdastm","btqeb","pfkrllrxw","ocby","irqvnxxouu","ildzpdimea","lzwhkxsn","ilddimea","ufybvbaozoqk","mxyevopfoimgjww","jhr","kcmwx","dvn","uzcof","glw","hbtnqebaj","riahv","w","qeugv","kfeuqyre","ilrdzpdimea","lplm","icinrbpql","scqlcmxw","bbmjnaxaml","e","rsac","bf","jwmqvpqds","tzteoovsyfwz","rc","lzwhkxs","jkgljikwamaqvf","tybizc","aplzuu","nrtyzifwytjblw","pze","bktcmwxk","uiykgmc","jsctk","npdbccbe","tybizcr"}
	};
};