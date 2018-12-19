from transitions.extensions import GraphMachine
import wptools, urllib.request, urllib.parse, re, wikipedia

from utils import send_text_message
from utils import send_image_message

def get_youtube_link(keyword):
        query_string = urllib.parse.urlencode({"search_query" : keyword})
        html_content = urllib.request.urlopen("http://www.youtube.com/results?" + query_string)
        search_results = re.findall(r'href=\"\/watch\?v=(.{11})', html_content.read().decode())
        return ("http://www.youtube.com/watch?v=" + search_results[0])
wikipedia.set_lang('zh-tw')

class TocMachine(GraphMachine):
    def __init__(self, **machine_configs):
        self.machine = GraphMachine(
            model=self,
            **machine_configs
        )

    def is_going_to_help(self, event):
        if event.get("message"):
            text = event['message']['text']
            return any(x in text.lower() for x in ['help', '幫助'])
        return False

    def is_going_to_by_nation(self, event):
        if event.get("message"):
            text = event['message']['text']
            return any(x in text.lower() for x in ['國家', 'nation', '重新選擇國家', 'reselect nation'])
        return False

    def is_going_to_usa(self, event):
        if event.get("message"):
            text = event['message']['text']
            return any(x in text.lower() for x in ['美國', 'usa', 'america', '重新選擇車種', 'reselect type'])
        return False

    def is_going_to_germany(self, event):
        if event.get("message"):
            text = event['message']['text']
            return any(x in text.lower() for x in ['德國', '得意志', '納粹', 'germany', 'nazi', '重新選擇車種', 'reselect type'])
        return False

    def is_going_to_ussr(self, event):
        if event.get("message"):
            text = event['message']['text']
            return any(x in text.lower() for x in ['蘇聯', '俄羅斯', 'ussr', 'russia', 'cccp', '重新選擇車種', 'reselect type'])
        return False

    def is_going_to_british(self, event):
        if event.get("message"):
            text = event['message']['text']
            return any(x in text.lower() for x in ['英國', '大英帝國', 'british', 'england', 'uk', '重新選擇車種', 'reselect type'])
        return False

    def is_going_to_by_type(self, event):
        if event.get("message"):
            text = event['message']['text']
            return any(x in text.lower() for x in ['車種', 'type', '重新選擇車種', 'reselect type'])
        return False

    def is_going_to_LT(self, event):
        if event.get("message"):
            text = event['message']['text']
            return any(x in text.lower() for x in ['輕型戰車', '輕型坦克', '輕坦', '輕戰', '輕型', 'light tank', 'light', 'lt', '重新選擇國家', 'reselect nation'])
        return False

    def is_going_to_MT(self, event):
        if event.get("message"):
            text = event['message']['text']
            return any(x in text.lower() for x in ['中型戰車', '中型坦克', '中坦', '中戰', '中型', 'medium tank', 'medium', 'mt', '重新選擇國家', 'reselect nation'])
        return False

    def is_going_to_HT(self, event):
        if event.get("message"):
            text = event['message']['text']
            return any(x in text.lower() for x in ['重型戰車', '重型坦克', '重坦', '重戰', '重型', 'heavy tank', 'heavy', 'ht', '重新選擇國家', 'reselect nation'])
        return False

    def is_going_to_TD(self, event):
        if event.get("message"):
            text = event['message']['text']
            return any(x in text.lower() for x in ['驅逐戰車', '驅逐坦克', '驅逐', 'tank destroyer', 'destroyer', 'td', '重新選擇國家', 'reselect nation'])
        return False

    def is_going_to_usa_LT(self, event):
        if event.get("message"):
            text = event['message']['text']
            return any(x in text.lower() for x in ['美國', 'usa', 'america', '輕型戰車', '輕型坦克', '輕坦', '輕戰', '輕型', 'light tank', 'light', 'lt', '重新選擇坦克', '重新選擇戰車', 'reselect tank'])
        return False

    def is_going_to_M2_LT(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'm2' == text.lower() 
        return False

    def is_going_to_M5(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'm5' == text.lower() 
        return False

    def is_going_to_M22(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'm22' == text.lower() 
        return False

    def is_going_to_M24(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'm24' == text.lower() 
        return False    

    def is_going_to_usa_MT(self, event):
        if event.get("message"):
            text = event['message']['text']
            return any(x in text.lower() for x in ['美國', 'usa', 'america', '中型戰車', '中型坦克', '中坦', '中戰', '中型', 'medium tank', 'medium', 'mt', '重新選擇坦克', '重新選擇戰車', 'reselect tank'])
        return False
    
    def is_going_to_M2_MT(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'm2' == text.lower() 
        return False

    def is_going_to_M3(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'm3' == text.lower() 
        return False

    def is_going_to_M4(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'm4' == text.lower() 
        return False

    def is_going_to_usa_HT(self, event):
        if event.get("message"):
            text = event['message']['text']
            return any(x in text.lower() for x in ['美國', 'usa', 'america', '重型戰車', '重型坦克', '重坦', '重戰', '重型', 'heavy tank', 'heavy', 'ht', '重新選擇坦克', '重新選擇戰車', 'reselect tank'])
        return False

    def is_going_to_M26(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'm26' == text.lower() 
        return False

    def is_going_to_usa_TD(self, event):
        if event.get("message"):
            text = event['message']['text']
            return any(x in text.lower() for x in ['美國', 'usa', 'america', '驅逐戰車', '驅逐坦克', '驅逐', 'tank destroyer', 'destroyer', 'td', '重新選擇坦克', '重新選擇戰車', 'reselect tank'])
        return False
    
    def is_going_to_M10(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'm10' == text.lower() 
        return False
    
    def is_going_to_M18(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'm18' == text.lower() 
        return False

    def is_going_to_M36(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'm36' == text.lower() 
        return False

    def is_going_to_germany_LT(self, event):
        if event.get("message"):
            text = event['message']['text']
            return any(x in text.lower() for x in ['德國', '得意志', '納粹', 'germany', 'nazi', '輕型戰車', '輕型坦克', '輕坦', '輕戰', '輕型', 'light tank', 'light', 'lt', '重新選擇坦克', '重新選擇戰車', 'reselect tank'])
        return False
    
    def is_going_to_PZ1(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'pz1' == text.lower() 
        return False

    def is_going_to_PZ2(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'pz2' == text.lower() 
        return False

    def is_going_to_LT35(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'lt35' == text.lower() 
        return False

    def is_going_to_LT38(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'lt38' == text.lower() 
        return False

    def is_going_to_germany_MT(self, event):
        if event.get("message"):
            text = event['message']['text']
            return any(x in text.lower() for x in ['德國', '得意志', '納粹', 'germany', 'nazi', '中型戰車', '中型坦克', '中坦', '中戰', '中型', 'medium tank', 'medium', 'mt', '重新選擇坦克', '重新選擇戰車', 'reselect tank'])
        return False

    def is_going_to_PZ3(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'pz3' == text.lower() 
        return False

    def is_going_to_PZ4(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'pz4' == text.lower() 
        return False
    
    def is_going_to_Panther(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'panther' == text.lower() 
        return False

    def is_going_to_germany_HT(self, event):
        if event.get("message"):
            text = event['message']['text']
            return any(x in text.lower() for x in ['德國', '得意志', '納粹', 'germany', 'nazi', '重型戰車', '重型坦克', '重坦', '重戰', '重型', 'heavy tank', 'heavy', 'ht', '重新選擇坦克', '重新選擇戰車', 'reselect tank'])
        return False

    def is_going_to_Tiger(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'tiger' == text.lower() 
        return False

    def is_going_to_Tiger2(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'tiger2' == text.lower() 
        return False

    def is_going_to_Maus(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'maus' == text.lower() 
        return False

    def is_going_to_germany_TD(self, event):
        if event.get("message"):
            text = event['message']['text']
            return any(x in text.lower() for x in ['德國', '得意志', '納粹', 'germany', 'nazi', '驅逐戰車', '驅逐坦克', '驅逐', 'tank destroyer', 'destroyer', 'td', '重新選擇坦克', '重新選擇戰車', 'reselect tank'])
        return False

    def is_going_to_PzJg1(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'pzjg1' == text.lower() 
        return False
    
    def is_going_to_Marder3(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'marder3' == text.lower() 
        return False
    
    def is_going_to_Hetzer(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'hetzer' == text.lower() 
        return False
    
    def is_going_to_Stug3(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'stug3' == text.lower() 
        return False

    def is_going_to_JgPz4(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'jgpz4' == text.lower() 
        return False

    def is_going_to_Nashorn(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'nashorn' == text.lower() 
        return False

    def is_going_to_JgPanther(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'jgpanther' == text.lower() 
        return False

    def is_going_to_SturmTigers(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'sturmtiger' == text.lower() 
        return False

    def is_going_to_JgTiger(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'jgtiger' == text.lower()
        return False

    def is_going_to_Ferdinand(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'ferdinand' == text.lower() 
        return False

    def is_going_to_ussr_LT(self, event):
        if event.get("message"):
            text = event['message']['text']
            return any(x in text.lower() for x in ['蘇聯', 'ussr', 'russia', 'cccp', '輕型戰車', '輕型坦克', '輕坦', '輕戰', '輕型', 'light tank', 'light', 'lt', '重新選擇坦克', '重新選擇戰車', 'reselect tank'])
        return False

    def is_going_to_BT7(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'bt-7' == text.lower() 
        return False

    def is_going_to_T26(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 't-26' == text.lower() 
        return False

    def is_going_to_T50(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 't-50' == text.lower() 
        return False

    def is_going_to_T60(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 't-60' == text.lower() 
        return False

    def is_going_to_T70(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 't-70' == text.lower() 
        return False

    def is_going_to_ussr_MT(self, event):
        if event.get("message"):
            text = event['message']['text']
            return any(x in text.lower() for x in ['蘇聯', 'ussr', 'russia', 'cccp', '中型戰車', '中型坦克', '中坦', '中戰', '中型', 'medium tank', 'medium', 'mt', '重新選擇坦克', '重新選擇戰車', 'reselect tank'])
        return False

    def is_going_to_T28(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 't-28' == text.lower() 
        return False

    def is_going_to_T34(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 't-34' == text.lower() 
        return False

    def is_going_to_T44(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 't-44' == text.lower() 
        return False

    def is_going_to_ussr_HT(self, event):
        if event.get("message"):
            text = event['message']['text']
            return any(x in text.lower() for x in ['蘇聯', 'ussr', 'russia', 'cccp', '重型戰車', '重型坦克', '重坦', '重戰', '重型', 'heavy tank', 'heavy', 'ht', '重新選擇坦克', '重新選擇戰車', 'reselect tank'])
        return False

    def is_going_to_KV1(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'kv-1' == text.lower() 
        return False

    def is_going_to_KV1S(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'kv-1s' == text.lower() 
        return False

    def is_going_to_KV2(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'kv-2' == text.lower() 
        return False

    def is_going_to_KV85(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'kv-85' == text.lower() 
        return False

    def is_going_to_IS2(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'is-2' == text.lower() 
        return False

    def is_going_to_IS3(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'is-3' == text.lower() 
        return False

    def is_going_to_ussr_TD(self, event):
        if event.get("message"):
            text = event['message']['text']
            return any(x in text.lower() for x in ['蘇聯', 'ussr', 'russia', 'cccp', '驅逐戰車', '驅逐坦克', '驅逐', 'tank destroyer', 'destroyer', 'td', '重新選擇坦克', '重新選擇戰車', 'reselect tank'])
        return False
    
    def is_going_to_Zis30(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'zis-30' == text.lower() 
        return False

    def is_going_to_SU76(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'su-76' == text.lower() 
        return False

    def is_going_to_SU85(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'su-85' == text.lower() 
        return False

    def is_going_to_SU100(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'su-100' == text.lower() 
        return False

    def is_going_to_SU122(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'su-122' == text.lower() 
        return False

    def is_going_to_SU152(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'su-152' == text.lower() 
        return False

    def is_going_to_ISU122(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'isu-122' == text.lower() 
        return False

    def is_going_to_ISU152(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'isu-152' == text.lower() 
        return False

    def is_going_to_british_LT(self, event):
        if event.get("message"):
            text = event['message']['text']
            return any(x in text.lower() for x in ['英國', '大英帝國', 'british', 'uk', 'england', '輕型戰車', '輕型坦克', '輕坦', '輕戰', '輕型', 'light tank', 'light', 'lt', '重新選擇坦克', '重新選擇戰車', 'reselect tank'])
        return False

    def is_going_to_MkVI(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'mkvi' == text.lower() 
        return False

    def is_going_to_Tetrarch(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'tetrarch' == text.lower() 
        return False

    def is_going_to_british_MT(self, event):
        if event.get("message"):
            text = event['message']['text']
            return any(x in text.lower() for x in ['英國', '大英帝國', 'british', 'uk', 'england', '中型戰車', '中型坦克', '中坦', '中戰', '中型', 'medium tank', 'medium', 'mt', '重新選擇坦克', '重新選擇戰車', 'reselect tank'])
        return False

    def is_going_to_Crusader(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'crusader' == text.lower() 
        return False

    def is_going_to_Cromwell(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'cromwell' == text.lower() 
        return False

    def is_going_to_Firefly(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'firefly' == text.lower() 
        return False

    def is_going_to_Comet(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'comet' == text.lower() 
        return False
    
    def is_going_to_british_HT(self, event):
        if event.get("message"):
            text = event['message']['text']
            return any(x in text.lower() for x in ['英國', '大英帝國', 'british', 'uk', 'england', '重型戰車', '重型坦克', '重坦', '重戰', '重型', 'heavy tank', 'heavy', 'ht', '重新選擇坦克', '重新選擇戰車', 'reselect tank'])
        return False

    def is_going_to_Matilda(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'matilda' == text.lower() 
        return False

    def is_going_to_Valetine(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'valetine' == text.lower() 
        return False

    def is_going_to_Churchill(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'churchill' == text.lower() 
        return False
    
    def is_going_to_british_TD(self, event):
        if event.get("message"):
            text = event['message']['text']
            return any(x in text.lower() for x in ['英國', '大英帝國', 'british', 'uk', 'england', '驅逐戰車', '驅逐坦克', '驅逐', 'tank destroyer', 'destroyer', 'td', '重新選擇坦克', '重新選擇戰車', 'reselect tank'])
        return False

    def is_going_to_Archer(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'archer' == text.lower() 
        return False

    def is_going_to_Achilles(self, event):
        if event.get("message"):
            text = event['message']['text']
            return 'achilles' == text.lower() 
        return False

    def on_enter_help(self, event):
        sender_id = event['sender']['id']
        send_text_message(sender_id,'您好，\n這是一個可以簡易查詢二戰坦克的TOCproject專頁，\n目前提供美德蘇英四個國家的知名坦克查詢，\n同時提供四種戰車，輕型、中型、重型、驅逐的車種類別\n欲開始查詢，請輸入"國家"或"車種"')

    def on_enter_by_nation(self, event):
        sender_id = event['sender']['id']
        send_text_message(sender_id,'您希望以"國家"進行搜索，\n目前支援"美國"，"德國"，"蘇聯"，"英國"，\n請輸入以上四個國家來進一步搜尋')

    def on_enter_usa(self, event):
        sender_id = event['sender']['id']
        send_text_message(sender_id,'您選擇了"美國"，\n美國在歷史上地大物博，資源豐富，生產的戰車為了適合在各地戰場爭戰而有通用的特色，來看看有哪些著名的戰車吧！\n美國可供搜尋的車種有"輕型戰車"，"中型戰車"，"重型戰車"，"驅逐戰車"')

    def on_enter_germany(self, event):
        sender_id = event['sender']['id']
        send_text_message(sender_id,'您選擇了"德國"，\n德國工業一向超群，在二戰中尤其集結了各項科技而有著超群的先進戰車，非常值得一看！，\n德國可供搜尋的車種有"輕型戰車"，"中型戰車"，"重型戰車"，"驅逐戰車"')

    def on_enter_ussr(self, event):
        sender_id = event['sender']['id']
        send_text_message(sender_id,'您選擇了"蘇聯"，\n蘇聯做為當年世界上最大的共產國家，軍事力量極強，但工業技術落後的狀況下，延伸出了一套獨特的戰車設計，\n蘇聯可供搜尋的車種有"輕型戰車"，"中型戰車"，"重型戰車"，"驅逐戰車"')

    def on_enter_british(self, event):
        sender_id = event['sender']['id']
        send_text_message(sender_id,'您選擇了"英國"，\n做為日不落帝國，歷史悠久的英國在戰車設計上有著獨到的美學以及堅持，就像個英國紳士一般，\n英國可供搜尋的車種有"輕型戰車"，"中型戰車"，"重型戰車"，"驅逐戰車"(註. 英國無以上戰車分類，故簡易的用裝甲程度區分)')

    def on_enter_by_type(self, event):
        sender_id = event['sender']['id']
        send_text_message(sender_id,'您希望以"車種"進行搜索，\n目前支援"輕型戰車"，"中型戰車"，"重型戰車"，"驅逐戰車"，\n請輸入以上四種車種來進一步搜尋')

    def on_enter_LT(self, event):
        sender_id = event['sender']['id']
        send_text_message(sender_id,'您選擇了"輕型戰車"，\n輕型戰車以優秀的機動性，造價成本低，人力需求少為特點，但同時也有著裝甲薄弱，火力貧下的弱勢，\n大戰初期因為技術，因此做為主要戰力，大戰中後期由於技術進步，輕型戰車逐漸式微，主要功用轉型為步兵協同作戰的掩護，\n請輸入"美國", "德國", "蘇聯", "英國"來進一步搜尋')

    def on_enter_MT(self, event):
        sender_id = event['sender']['id']
        send_text_message(sender_id,'您選擇了"中型戰車"，\n中型戰車有著輕型與重型戰車的兩者綜合，形成了一個非常通用的載具，\n大戰期間生產數量最多的，也是最主要火力的中型戰車，戰後演變成了MBT，繼續在陸上稱霸，\n請輸入"美國", "德國", "蘇聯", "英國"來進一步搜尋')

    def on_enter_HT(self, event):
        sender_id = event['sender']['id']
        send_text_message(sender_id,'您選擇了"重型戰車"，\n重型戰車有著強大的火力，厚重的裝甲，足以威嚇敵人，但卻犧牲了機動性，造價昂貴，維修麻煩，人力需求大，\n故大戰中後期，重型戰車佔了很重要的環節，若某方有重型戰車，對敵方來說是一個極大的精神壓力，\n請輸入"美國", "德國", "蘇聯", "英國"來進一步搜尋')

    def on_enter_TD(self, event):
        sender_id = event['sender']['id']
        send_text_message(sender_id,'您選擇了"驅逐戰車"，\n驅逐戰車是一個特殊的分支，有著強大的火力，多數缺少可旋轉的頭，裝甲從貧弱到厚重都有，這是因為大戰中後期物資缺乏，許多國家拿既有的戰車底盤加上不可動的上裝甲後，並加裝大口徑火砲，來彌補一般戰車生產不足的問題，\n其中大口徑火砲多為原本的固定式反戰車砲，拿來快速生產跟防禦敵人再適合也不過了，\n請輸入"美國", "德國", "蘇聯", "英國"來進一步搜尋')

    def on_enter_usa_LT(self, event):
        sender_id = event['sender']['id']
        send_text_message(sender_id,'您選擇了美國輕型戰車，目前有"M2", "M5", "M22", "M24"四種輕型戰車可供搜索，請輸入以上關鍵字觀看以上戰車的資料')

    def on_enter_M2_LT(self, event):
        sender_id = event['sender']['id']
        title = 'M2輕型戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('m2 light tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_M5(self, event):
        sender_id = event['sender']['id']
        title = 'M3/M5斯圖亞特戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('m3 stuart tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_M22(self, event):
        sender_id = event['sender']['id']
        title = 'M22蝗蟲式輕型坦克'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('m22 locust tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_M24(self, event):
        sender_id = event['sender']['id']
        title = 'M24霞飛戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('m24 chaffee tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_usa_MT(self, event):
        sender_id = event['sender']['id']
        send_text_message(sender_id,'您選擇了美國中型戰車，目前有"M2", "M3", "M4"三種中型戰車可供搜索，請輸入以上關鍵字觀看以上戰車的資料')

    def on_enter_M2_MT(self, event):
        sender_id = event['sender']['id']
        title = 'M2中型坦克'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('m2 medium tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_M3(self, event):
        sender_id = event['sender']['id']
        title = 'M3李戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('m3 lee tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_M4(self, event):
        sender_id = event['sender']['id']
        title = 'M4雪曼戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('m4 sherman tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_usa_HT(self, event):
        sender_id = event['sender']['id']
        send_text_message(sender_id,'您選擇了美國重型戰車，目前有"M26"一種重型戰車可供搜索，請輸入以上關鍵字觀看以上戰車的資料')

    def on_enter_M26(self, event):
        sender_id = event['sender']['id']
        title = 'M26潘興戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('M26 Pershing tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_usa_TD(self, event):
        sender_id = event['sender']['id']
        send_text_message(sender_id,'您選擇了美國驅逐戰車，目前有"M10", "M18", "M36"三種驅逐戰車可供搜索，請輸入以上關鍵字觀看以上戰車的資料')

    def on_enter_M10(self, event):
        sender_id = event['sender']['id']
        title = 'M10驅逐戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('M10 tank destroyer ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_M18(self, event):
        sender_id = event['sender']['id']
        title = 'M18驅逐戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('M18 tank destroyer ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_M36(self, event):
        sender_id = event['sender']['id']
        title = 'M36驅逐戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('M36 tank destroyer ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_germany_LT(self, event):
        sender_id = event['sender']['id']
        send_text_message(sender_id,'您選擇了德國輕型戰車，目前有"PZ1", "PZ2", "LT35", "LT38"四種輕型戰車可供搜索，請輸入以上關鍵字觀看以上戰車的資料')

    def on_enter_PZ1(self, event):
        sender_id = event['sender']['id']
        title = '一號戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('pz i light tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_PZ2(self, event):
        sender_id = event['sender']['id']
        title = '二號戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('pz ii light tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_LT35(self, event):
        sender_id = event['sender']['id']        
        title = 'LT-35戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('LT-35 light tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_LT38(self, event):
        sender_id = event['sender']['id']
        title = 'LT-38戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('LT-38 light tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_germany_MT(self, event):
        sender_id = event['sender']['id']
        send_text_message(sender_id,'您選擇了德國中型戰車，目前有"PZ3", "PZ4", "Panther"三種中型戰車可供搜索，請輸入以上關鍵字觀看以上戰車的資料')

    def on_enter_PZ3(self, event):
        sender_id = event['sender']['id']
        title = '三號戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('pz iii medium tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_PZ4(self, event):
        sender_id = event['sender']['id']
        title = '四號戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('pz iv medium tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_Panther(self, event):
        sender_id = event['sender']['id']
        title = '豹式戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('panther medium tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_germany_HT(self, event):
        sender_id = event['sender']['id']
        send_text_message(sender_id,'您選擇了德國重型戰車，目前有"Tiger", "Tiger2", "Maus"三種重型戰車可供搜索，請輸入以上關鍵字觀看以上戰車的資料')

    def on_enter_Tiger(self, event):
        sender_id = event['sender']['id']
        title = '虎I戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('tiger i heavy tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_Tiger2(self, event):
        sender_id = event['sender']['id']
        title = '虎II戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('tiger ii heavy tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_Maus(self, event):
        sender_id = event['sender']['id']
        title = '八號戰車鼠式'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('maus heavy tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_germany_TD(self, event):
        sender_id = event['sender']['id']
        send_text_message(sender_id,'您選擇了德國驅逐戰車，目前有"PzJg1", "Marder3", "Hetzer", "Stug3", "JgPz4", "Nashorn", "JgPanther", "SturmTiger", "JgTiger", "Ferdinand"十種驅逐戰車可供搜索，請輸入以上關鍵字觀看以上戰車的資料')

    def on_enter_PzJg1(self, event):
        sender_id = event['sender']['id']
        title = '一號驅逐戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('pzjg i tank destroyer ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_Marder3(self, event):
        sender_id = event['sender']['id']
        title = '黃鼠狼III驅逐戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('marder iii tank destroyer ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_Hetzer(self, event):
        sender_id = event['sender']['id']
        title = '追獵者式驅逐戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('hetzer tank destroyer ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_Stug3(self, event):
        sender_id = event['sender']['id']
        title = '三號突擊砲'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('stug iii tank destroyer ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_JgPz4(self, event):
        sender_id = event['sender']['id']
        title = '四號驅逐戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('jgpz iv tank destroyer ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_Nashorn(self, event):
        sender_id = event['sender']['id']
        title = '犀牛式驅逐戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('nashorn tank destroyer ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_JgPanther(self, event):
        sender_id = event['sender']['id']
        title = '獵豹式驅逐戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('jgpanther tank destroyer ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_SturmTiger(self, event):
        sender_id = event['sender']['id']
        title = '突擊虎式'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('sturmtiger tank destroyer ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_JgTiger(self, event):
        sender_id = event['sender']['id']
        title = '獵虎式驅逐戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('jgtiger tank destroyer ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_Ferdinand(self, event):
        sender_id = event['sender']['id']
        title = '象式重驅逐戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('ferdinand tank destroyer ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_ussr_LT(self, event):
        sender_id = event['sender']['id']
        send_text_message(sender_id,'您選擇了蘇聯輕型戰車，目前有"BT-7", "T-26", "T-50", "T-60", "T-70"五種輕型戰車可供搜索，請輸入以上關鍵字觀看以上戰車的資料')

    def on_enter_BT7(self, event):
        sender_id = event['sender']['id']
        title = 'BT坦克'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('bt-7 light tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_T26(self, event):
        sender_id = event['sender']['id']
        title = 'T-26戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('t-26 light tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_T50(self, event):
        sender_id = event['sender']['id']
        title = 'T-50坦克'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('t-50 light tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_T60(self, event):
        sender_id = event['sender']['id']
        title = 'T-60坦克'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('t-60 light tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_T70(self, event):
        sender_id = event['sender']['id']
        title = 'T-70坦克'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('t-70 light tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_ussr_MT(self, event):
        sender_id = event['sender']['id']
        send_text_message(sender_id,'您選擇了蘇聯中型戰車，目前有"T-28", "T-34", "T-44"三種中型戰車可供搜索，請輸入以上關鍵字觀看以上戰車的資料')

    def on_enter_T28(self, event):
        sender_id = event['sender']['id']
        title = 'T-28坦克'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('t-28 medium tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_T34(self, event):
        sender_id = event['sender']['id']
        title = 'T-34戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('t-34 medium tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_T44(self, event):
        sender_id = event['sender']['id']
        title = 'T-44坦克'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('t-44 medium tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_ussr_HT(self, event):
        sender_id = event['sender']['id']
        send_text_message(sender_id,'您選擇了蘇聯重型戰車，目前有"KV-1", "KV-1S", "KV-2", "KV-85", "IS-2" ,"IS-3"六種重型戰車可供搜索，請輸入以上關鍵字觀看以上戰車的資料')

    def on_enter_KV1(self, event):
        sender_id = event['sender']['id']
        title = 'KV-1坦克'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('kv-1 heavy tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_KV1S(self, event):
        sender_id = event['sender']['id']
        title = 'KV-1S重型戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('kv-1s heavy tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_KV2(self, event):
        sender_id = event['sender']['id']
        title = 'KV-2戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('kv-2 heavy tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_KV85(self, event):
        sender_id = event['sender']['id']
        title = 'KV-85坦克'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('kv-85 heavy tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_IS2(self, event):
        sender_id = event['sender']['id']
        title = 'IS-2重型坦克'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('is-2 heavy tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_IS3(self, event):
        sender_id = event['sender']['id']
        title = 'IS-3重型戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('is-3 heavy tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_ussr_TD(self, event):
        sender_id = event['sender']['id']
        send_text_message(sender_id,'您選擇了蘇聯驅逐戰車，目前有"Zis-30", "SU-76", "SU-85", "SU-100", "SU-122", "SU-152" ,"ISU-122", "ISU-152"八種驅逐戰車可供搜索，請輸入以上關鍵字觀看以上戰車的資料')

    def on_enter_Zis30(self, event):
        sender_id = event['sender']['id']
        title = 'ZiS-30'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('ZiS-30 tank destroyer ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))


    def on_enter_SU76(self, event):
        sender_id = event['sender']['id']
        title = 'SU-76'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('SU-76 tank destroyer ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))


    def on_enter_SU85(self, event):
        sender_id = event['sender']['id']
        title = 'SU-85驅逐坦克'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('SU-85 tank destroyer ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_SU100(self, event):
        sender_id = event['sender']['id']
        title = 'SU-100驅逐戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('SU-100 tank destroyer ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_SU122(self, event):
        sender_id = event['sender']['id']
        title = 'SU-122突擊炮'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('SU-122 tank destroyer ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_SU152(self, event):
        sender_id = event['sender']['id']
        title = 'SU-152'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('SU-152 tank destroyer ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_ISU122(self, event):
        sender_id = event['sender']['id']
        title = 'ISU-152式重型突擊炮'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('ISU-122 tank destroyer ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_ISU152(self, event):
        sender_id = event['sender']['id']
        title = 'ISU-152式重型突擊炮'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('ISU-152 tank destroyer ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_british_LT(self, event):
        sender_id = event['sender']['id']
        send_text_message(sender_id,'您選擇了英國輕型戰車，目前有"MkVI", "Tetrarch"二種輕型戰車可供搜索，請輸入以上關鍵字觀看以上戰車的資料')

    def on_enter_MkVI(self, event):
        sender_id = event['sender']['id']
        title = 'Mk.VI輕型坦克'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('mk.vi tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_Tetrarch(self, event):
        sender_id = event['sender']['id']
        title = 'Mk.VII領主式輕型坦克'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('tetrarch tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_british_MT(self, event):
        sender_id = event['sender']['id']
        send_text_message(sender_id,'您選擇了英國中型戰車，目前有"Crusader", "Cromwell", "Firefly", "Comet"四種中型戰車可供搜索，請輸入以上關鍵字觀看以上戰車的資料')

    def on_enter_Crusader(self, event):
        sender_id = event['sender']['id']
        title = '十字軍坦克'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('crusader tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))


    def on_enter_Cromwell(self, event):
        sender_id = event['sender']['id']
        title = '克倫威爾戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('cromwell tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))


    def on_enter_Firefly(self, event):
        sender_id = event['sender']['id']
        title = '雪曼螢火蟲坦克'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('firefly tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_Comet(self, event):
        sender_id = event['sender']['id']
        title = '彗星坦克'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('comet tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_british_HT(self, event):
        sender_id = event['sender']['id']
        send_text_message(sender_id,'您選擇了英國重型戰車，目前有"Matilda", "Valetine", "Churchill"三種重型戰車可供搜索，請輸入以上關鍵字觀看以上戰車的資料')

    def on_enter_Matilda(self, event):
        sender_id = event['sender']['id']
        title = '瑪蒂達 II'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('matilda tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_Valetine(self, event):
        sender_id = event['sender']['id']
        title = '瓦倫丁戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('valentine tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_Churchill(self, event):
        sender_id = event['sender']['id']
        title = '丘吉爾戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('churchill tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    def on_enter_british_TD(self, event):
        sender_id = event['sender']['id']
        send_text_message(sender_id,'您選擇了英國驅逐戰車，目前有"Archer", "Achilles"兩種驅逐戰車可供搜索，請輸入以上關鍵字觀看以上戰車的資料')

    def on_enter_Archer(self, event):
        sender_id = event['sender']['id']
        title = '射手驅逐戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('archer tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))
    
    def on_enter_Achilles(self, event):
        sender_id = event['sender']['id']
        title = '阿基里斯驅逐戰車'
        page = wptools.page(title, lang='zh-tw').get_query()
        send_image_message(sender_id,page.images()[0]['url'])
        send_text_message(sender_id,get_youtube_link('achilles tank ww2'))
        send_text_message(sender_id,wikipedia.summary(title, sentences=10))

    
        


    
