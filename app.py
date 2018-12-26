from bottle import route, run, request, abort, static_file
import os
from fsm import TocMachine

VERIFY_TOKEN = os.environ['VERIFY_TOKEN']
PORT = os.environ['PORT']

machine = TocMachine(
    states=[
        'user',
        'help',
        'helphelp',
        'by_nation',
            'usa',
            'germany',
            'ussr',
            'british',
        'by_type',
            'LT',
            'MT',
            'HT',
            'TD',
                'usa_LT',
                    'M2_LT',
                    'M5',
                    'M22',            
                    'M24',
                'usa_MT',
                    'M2_MT',
                    'M3',
                    'M4',
                'usa_HT',
                    'M26',
                'usa_TD',
                    'M10',
                    'M18',
                    'M36',
                'germany_LT',
                    'PZ1',
                    'PZ2',
                    'LT35',
                    'LT38',
                'germany_MT',
                    'PZ3',
                    'PZ4',
                    'Panther',
                'germany_HT',
                    'Tiger',
                    'Tiger2',
                    'Maus',
                'germany_TD',
                    'PzJg1',
                    'Marder3',
                    'Hetzer',
                    'Stug3',
                    'JgPz4',
                    'Nashorn',
                    'JgPanther',
                    'SturmTiger',
                    'JgTiger',
                    'Ferdinand',
                'ussr_LT',
                    'BT7',
                    'T26',
                    'T50',
                    'T60',
                    'T70',
                'ussr_MT',
                    'T28',
                    'T34',
                    'T44',
                'ussr_HT',
                    'KV1',
                    'KV1S',
                    'KV2',
                    'KV85',
                    'IS2',
                    'IS3',
                'ussr_TD',
                    'Zis30',
                    'SU76',
                    'SU85',
                    'SU100',
                    'SU122',
                    'SU152',
                    'ISU122',
                    'ISU152',
                'british_LT',
                    'MkVI',
                    'Tetrarch',
                'british_MT',
                    'Crusader',
                    'Cromwell',
                    'Firefly',
                    'Comet',
                'british_HT',
                    'Matilda',
                    'Valetine',
                    'Churchill',
                'british_TD',
                    'Archer',
                    'Achilles'         
    ],
    transitions=[
        {
            'trigger': 'wakeup',
            'source': 'user',
            'dest': 'help',
        },
        {
            'trigger': 'advance',
            'source': [
                'user',
                'help',
                'by_nation',
                    'usa',
                    'germany',
                    'ussr',
                    'british',
                'by_type',
                    'LT',
                    'MT',
                    'HT',
                    'TD',
                        'usa_LT',
                            'M2_LT',
                            'M5',
                            'M22',            
                            'M24',
                        'usa_MT',
                            'M2_MT',
                            'M3',
                            'M4',
                        'usa_HT',
                            'M26',
                        'usa_TD',
                            'M10',
                            'M18',
                            'M36',
                        'germany_LT',
                            'PZ1',
                            'PZ2',
                            'LT35',
                            'LT38',
                        'germany_MT',
                            'PZ3',
                            'PZ4',
                            'Panther',
                        'germany_HT',
                            'Tiger',
                            'Tiger2',
                            'Maus',
                        'germany_TD',
                            'PzJg1',
                            'Marder3',
                            'Hetzer',
                            'Stug3',
                            'JgPz4',
                            'Nashorn',
                            'JgPanther',
                            'SturmTiger',
                            'JgTiger',
                            'Ferdinand',
                        'ussr_LT',
                            'BT7',
                            'T26',
                            'T50',
                            'T60',
                            'T70',
                        'ussr_MT',
                            'T28',
                            'T34',
                            'T44',
                        'ussr_HT',
                            'KV1',
                            'KV1S',
                            'KV2',
                            'KV85',
                            'IS2',
                            'IS3',
                        'ussr_TD',
                            'Zis30',
                            'SU76',
                            'SU85',
                            'SU100',
                            'SU122',
                            'SU152',
                            'ISU122',
                            'ISU152',
                        'british_LT',
                            'MkVI',
                            'Tetrarch',
                        'british_MT',
                            'Crusader',
                            'Cromwell',
                            'Firefly',
                            'Comet',
                        'british_HT',
                            'Matilda',
                            'Valetine',
                            'Churchill',
                        'british_TD',
                            'Archer',
                            'Achilles'                 
            ],
            'dest': 'help',
            'conditions': 'is_going_to_help'
        },
        {
            'trigger': 'advance',
            'source': 'help',
            'dest': 'helphelp',
            'conditions': 'is_going_to_by_helphelp'
        },
        {
            'trigger': 'advance',
            'source': [
                'help',
                'usa',
                'germany',
                'ussr',
                'british'
            ],
            'dest': 'by_nation',
            'conditions': 'is_going_to_by_nation'
        },
            {
            'trigger': 'advance',
            'source': [
                'by_nation',
                'usa_LT',
                'usa_MT',
                'usa_HT',
                'usa_TD'
            ],
            'dest': 'usa',
            'conditions': 'is_going_to_usa'
            },
            {
            'trigger': 'advance',
            'source': [
                'by_nation',
                'germany_LT',
                'germany_MT',
                'germany_HT',
                'germany_TD'
            ],
            'dest': 'germany',
            'conditions': 'is_going_to_germany'
            },
            {
            'trigger': 'advance',
            'source': [
                'by_nation',
                'ussr_LT',
                'ussr_MT',
                'ussr_HT',
                'ussr_TD'
            ],
            'dest': 'ussr',
            'conditions': 'is_going_to_ussr'
            },
            {
            'trigger': 'advance',
            'source': [
                'by_nation',
                'british_LT',
                'british_MT',
                'british_HT',
                'british_TD'
            ],
            'dest': 'british',
            'conditions': 'is_going_to_british'
            },
        {
            'trigger': 'advance',
            'source': [
                'help',
                'LT',
                'MT',
                'HT',
                'TD'
            ],
            'dest': 'by_type',
            'conditions': 'is_going_to_by_type'
        },
            {
            'trigger': 'advance',
            'source': [
                'by_type',
                'usa_LT',
                'germany_LT',
                'ussr_LT',
                'british_LT'
            ],
            'dest': 'LT',
            'conditions': 'is_going_to_LT'
            },
            {
            'trigger': 'advance',
            'source': [
                'by_type',
                'usa_MT',
                'germany_MT',
                'ussr_MT',
                'british_MT'
            ],
            'dest': 'MT',
            'conditions': 'is_going_to_MT'
            },
            {
            'trigger': 'advance',
            'source': [
                'by_type',
                'usa_HT',
                'germany_HT',
                'ussr_HT',
                'british_HT'
            ],
            'dest': 'HT',
            'conditions': 'is_going_to_HT'
            },
            {
            'trigger': 'advance',
            'source': [
                'by_type',
                'usa_TD',
                'germany_TD',
                'ussr_TD',
                'british_TD'
            ],
            'dest': 'TD',
            'conditions': 'is_going_to_TD'
            },
                {
                'trigger': 'advance',
                'source': [
                    'usa',
                    'LT',
                    'M2_LT',
                    'M5',
                    'M22',
                    'M24'
                ],
                'dest': 'usa_LT',
                'conditions': 'is_going_to_usa_LT'
                },
                    {
                    'trigger': 'advance',
                    'source': 'usa_LT',
                    'dest': 'M2_LT',
                    'conditions': 'is_going_to_M2_LT'
                    }, 
                    {
                    'trigger': 'advance',
                    'source': 'usa_LT',
                    'dest': 'M5',
                    'conditions': 'is_going_to_M5'
                    },
                    {
                    'trigger': 'advance',
                    'source': 'usa_LT',
                    'dest': 'M22',
                    'conditions': 'is_going_to_M22'
                    },
                    {
                    'trigger': 'advance',
                    'source': 'usa_LT',
                    'dest': 'M24',
                    'conditions': 'is_going_to_M24'
                    },
                {
                'trigger': 'advance',
                'source': [
                    'usa',
                    'MT',
                    'M2_MT',
                    'M3',
                    'M4'
                ],
                'dest': 'usa_MT',
                'conditions': 'is_going_to_usa_MT'    
                },
                    {
                    'trigger': 'advance',
                    'source': 'usa_MT',
                    'dest': 'M2_MT',
                    'conditions': 'is_going_to_M2_MT'
                    },
                    {
                    'trigger': 'advance',
                    'source': 'usa_MT',
                    'dest': 'M3',
                    'conditions': 'is_going_to_M3'
                    },
                    {
                    'trigger': 'advance',
                    'source': 'usa_MT',
                    'dest': 'M4',
                    'conditions': 'is_going_to_M4'
                    },
                {
                'trigger': 'advance',
                'source': [
                    'usa',
                    'HT',
                    'M26'
                ],
                'dest': 'usa_HT',
                'conditions': 'is_going_to_usa_HT'    
                },
                    {
                    'trigger': 'advance',
                    'source': 'usa_HT',
                    'dest': 'M26',
                    'conditions': 'is_going_to_M26'
                    },
                {
                'trigger': 'advance',
                'source': [
                    'usa',
                    'TD',
                    'M10',
                    'M18',
                    'M36'
                ],
                'dest': 'usa_TD',
                'conditions': 'is_going_to_usa_TD'    
                },
                    {
                    'trigger': 'advance',
                    'source': 'usa_TD',
                    'dest': 'M10',
                    'conditions': 'is_going_to_M10'
                    },
                    {
                    'trigger': 'advance',
                    'source': 'usa_TD',
                    'dest': 'M18',
                    'conditions': 'is_going_to_M18'
                    },
                    {
                    'trigger': 'advance',
                    'source': 'usa_TD',
                    'dest': 'M36',
                    'conditions': 'is_going_to_M36'
                    },
                {
                'trigger': 'advance',
                'source': [
                    'germany',
                    'LT',
                    'PZ1',
                    'PZ2',
                    'LT35',
                    'LT38'
                ],
                'dest': 'germany_LT',
                'conditions': 'is_going_to_germany_LT'    
                },
                    {
                    'trigger': 'advance',
                    'source': 'germany_LT',
                    'dest': 'PZ1',
                    'conditions': 'is_going_to_PZ1'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'germany_LT',
                    'dest': 'PZ2',
                    'conditions': 'is_going_to_PZ2'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'germany_LT',
                    'dest': 'LT35',
                    'conditions': 'is_going_to_LT35'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'germany_LT',
                    'dest': 'LT38',
                    'conditions': 'is_going_to_LT38'    
                    },
                {
                'trigger': 'advance',
                'source': [
                    'germany',
                    'MT',
                    'PZ3',
                    'PZ4',
                    'Panther'
                ],
                'dest': 'germany_MT',
                'conditions': 'is_going_to_germany_MT'    
                },
                    {
                    'trigger': 'advance',
                    'source': 'germany_MT',
                    'dest': 'PZ3',
                    'conditions': 'is_going_to_PZ3'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'germany_MT',
                    'dest': 'PZ4',
                    'conditions': 'is_going_to_PZ4'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'germany_MT',
                    'dest': 'Panther',
                    'conditions': 'is_going_to_Panther'    
                    },
                {
                'trigger': 'advance',
                'source': [
                    'germany',
                    'HT',
                    'Tiger',
                    'Tiger2',
                    'Maus'
                ],
                'dest': 'germany_HT',
                'conditions': 'is_going_to_germany_HT'    
                },
                    {
                    'trigger': 'advance',
                    'source': 'germany_HT',
                    'dest': 'Tiger',
                    'conditions': 'is_going_to_Tiger'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'germany_HT',
                    'dest': 'Tiger2',
                    'conditions': 'is_going_to_Tiger2'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'germany_HT',
                    'dest': 'Maus',
                    'conditions': 'is_going_to_Maus'    
                    },
                {
                'trigger': 'advance',
                'source': [
                    'germany',
                    'TD',
                    'PzJg1',
                    'Marder3',
                    'Hetzer',
                    'Stug3',
                    'JgPz4',
                    'Nashorn',
                    'JgPanther',
                    'SturmTiger',
                    'JgTiger',
                    'Ferdinand'
                ],
                'dest': 'germany_TD',
                'conditions': 'is_going_to_germany_TD'    
                },
                    {
                    'trigger': 'advance',
                    'source': 'germany_TD',
                    'dest': 'PzJg1',
                    'conditions': 'is_going_to_PzJg1'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'germany_TD',
                    'dest': 'Marder3',
                    'conditions': 'is_going_to_Marder3'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'germany_TD',
                    'dest': 'Hetzer',
                    'conditions': 'is_going_to_Hetzer'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'germany_TD',
                    'dest': 'Stug3',
                    'conditions': 'is_going_to_Stug3'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'germany_TD',
                    'dest': 'JgPz4',
                    'conditions': 'is_going_to_JgPz4'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'germany_TD',
                    'dest': 'Nashorn',
                    'conditions': 'is_going_to_Nashorn'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'germany_TD',
                    'dest': 'JgPanther',
                    'conditions': 'is_going_to_JgPanther'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'germany_TD',
                    'dest': 'SturmTiger',
                    'conditions': 'is_going_to_SturmTiger'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'germany_TD',
                    'dest': 'JgTiger',
                    'conditions': 'is_going_to_JgTiger'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'germany_TD',
                    'dest': 'Ferdinand',
                    'conditions': 'is_going_to_Ferdinand'    
                    },
                {
                'trigger': 'advance',
                'source': [
                    'ussr',
                    'LT',
                    'BT7',
                    'T26',
                    'T50',
                    'T60',
                    'T70'
                ],
                'dest': 'ussr_LT',
                'conditions': 'is_going_to_ussr_LT'    
                },
                    {
                    'trigger': 'advance',
                    'source': 'ussr_LT',
                    'dest': 'BT7',
                    'conditions': 'is_going_to_BT7'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'ussr_LT',
                    'dest': 'T26',
                    'conditions': 'is_going_to_T26'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'ussr_LT',
                    'dest': 'T50',
                    'conditions': 'is_going_to_T50'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'ussr_LT',
                    'dest': 'T60',
                    'conditions': 'is_going_to_T60'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'ussr_LT',
                    'dest': 'T70',
                    'conditions': 'is_going_to_T70'    
                    },
                {
                'trigger': 'advance',
                'source': [
                    'ussr',
                    'MT',
                    'T28',
                    'T34',
                    'T44'
                ],
                'dest': 'ussr_MT',
                'conditions': 'is_going_to_ussr_MT'    
                },
                    {
                    'trigger': 'advance',
                    'source': 'ussr_MT',
                    'dest': 'T28',
                    'conditions': 'is_going_to_T28'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'ussr_MT',
                    'dest': 'T34',
                    'conditions': 'is_going_to_T34'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'ussr_MT',
                    'dest': 'T44',
                    'conditions': 'is_going_to_T44'    
                    },
                {
                'trigger': 'advance',
                'source': [
                    'ussr',
                    'HT',
                    'KV1',
                    'KV1S',
                    'KV2',
                    'KV85',
                    'IS2',
                    'IS3'
                ],
                'dest': 'ussr_HT',
                'conditions': 'is_going_to_ussr_HT'    
                },
                    {
                    'trigger': 'advance',
                    'source': 'ussr_HT',
                    'dest': 'KV1',
                    'conditions': 'is_going_to_KV1'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'ussr_HT',
                    'dest': 'KV1S',
                    'conditions': 'is_going_to_KV1S'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'ussr_HT',
                    'dest': 'KV2',
                    'conditions': 'is_going_to_KV2'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'ussr_HT',
                    'dest': 'KV85',
                    'conditions': 'is_going_to_KV85'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'ussr_HT',
                    'dest': 'IS2',
                    'conditions': 'is_going_to_IS2'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'ussr_HT',
                    'dest': 'IS3',
                    'conditions': 'is_going_to_IS3'    
                    },
                {
                'trigger': 'advance',
                'source': [
                    'ussr',
                    'TD',
                    'Zis30',
                    'SU76',
                    'SU85',
                    'SU100',
                    'SU122',
                    'SU152',
                    'ISU122',
                    'ISU152'
                ],
                'dest': 'ussr_TD',
                'conditions': 'is_going_to_ussr_TD'    
                },
                    {
                    'trigger': 'advance',
                    'source': 'ussr_TD',
                    'dest': 'Zis30',
                    'conditions': 'is_going_to_Zis30'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'ussr_TD',
                    'dest': 'SU76',
                    'conditions': 'is_going_to_SU76'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'ussr_TD',
                    'dest': 'SU85',
                    'conditions': 'is_going_to_SU85'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'ussr_TD',
                    'dest': 'SU100',
                    'conditions': 'is_going_to_SU100'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'ussr_TD',
                    'dest': 'SU122',
                    'conditions': 'is_going_to_SU122'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'ussr_TD',
                    'dest': 'SU152',
                    'conditions': 'is_going_to_SU152'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'ussr_TD',
                    'dest': 'ISU122',
                    'conditions': 'is_going_to_ISU122'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'ussr_TD',
                    'dest': 'ISU152',
                    'conditions': 'is_going_to_ISU152'    
                    },
                {
                'trigger': 'advance',
                'source': [
                    'british',
                    'LT',
                    'MkVI',
                    'Tetrarch'
                ],
                'dest': 'british_LT',
                'conditions': 'is_going_to_british_LT'    
                },
                    {
                    'trigger': 'advance',
                    'source': 'british_LT',
                    'dest': 'MkVI',
                    'conditions': 'is_going_to_MkVI'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'british_LT',
                    'dest': 'Tetrarch',
                    'conditions': 'is_going_to_Tetrarch'    
                    },
                {
                'trigger': 'advance',
                'source': [
                    'british',
                    'MT',
                    'Crusader',
                    'Cromwell',
                    'Firefly',
                    'Comet'
                ],
                'dest': 'british_MT',
                'conditions': 'is_going_to_british_MT'
                },
                    {
                    'trigger': 'advance',
                    'source': 'british_MT',
                    'dest': 'Crusader',
                    'conditions': 'is_going_to_Crusader'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'british_MT',
                    'dest': 'Cromwell',
                    'conditions': 'is_going_to_Cromwell'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'british_MT',
                    'dest': 'Firefly',
                    'conditions': 'is_going_to_Firefly'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'british_MT',
                    'dest': 'Comet',
                    'conditions': 'is_going_to_Comet'    
                    },
                {
                'trigger': 'advance',
                'source': [
                    'british',
                    'HT',
                    'Matilda',
                    'Valetine',
                    'Churchill'
                ],
                'dest': 'british_HT',
                'conditions': 'is_going_to_british_HT'    
                },
                    {
                    'trigger': 'advance',
                    'source': 'british_HT',
                    'dest': 'Matilda',
                    'conditions': 'is_going_to_Matilda'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'british_HT',
                    'dest': 'Valetine',
                    'conditions': 'is_going_to_Valetine'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'british_HT',
                    'dest': 'Churchill',
                    'conditions': 'is_going_to_Churchill'    
                    },
                {
                'trigger': 'advance',
                'source': [
                    'british',
                    'TD',
                    'Archer',
                    'Achilles'
                ],
                'dest': 'british_TD',
                'conditions': 'is_going_to_british_TD'    
                },
                    {
                    'trigger': 'advance',
                    'source': 'british_TD',
                    'dest': 'Archer',
                    'conditions': 'is_going_to_Archer'    
                    },
                    {
                    'trigger': 'advance',
                    'source': 'british_TD',
                    'dest': 'Achilles',
                    'conditions': 'is_going_to_Achilles'    
                    }
    ],
    initial='user',
    auto_transitions=False,
    show_conditions=True,
)


@route("/webhook", method="GET")
def setup_webhook():
    mode = request.GET.get("hub.mode")
    token = request.GET.get("hub.verify_token")
    challenge = request.GET.get("hub.challenge")

    if mode == "subscribe" and token == VERIFY_TOKEN:
        print("WEBHOOK_VERIFIED")
        return challenge

    else:
        abort(403)


@route("/webhook", method="POST")
def webhook_handler():
    body = request.json
    print('\nFSM STATE: ' + machine.state)
    print('REQUEST BODY: ')
    print(body)

    if body['object'] == "page":
        event = body['entry'][0]['messaging'][0]
        if machine.state == 'user':
            machine.wakeup(event)
        else:    
            machine.advance(event)
        return 'OK'


@route('/show-fsm', methods=['GET'])
def show_fsm():
    machine.get_graph().draw('fsm.png', prog='dot', format='png')
    return static_file('fsm.png', root='./', mimetype='image/png')

if __name__ == "__main__":
    #show_fsm()
    run(host="0.0.0.0", port=PORT, debug=True, reloader=True, threaded=True)
