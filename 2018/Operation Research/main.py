from PyQt5 import QtWidgets, QtCore
from PyQt5.QtWidgets import QProgressDialog
from PyQt5.QtCore import QThread, pyqtSignal, QObject
import OR_Project_UI
import sys
sys.path.append('./map_data')
import driving_value, transit_value, walking_value
import google_map, TSP_faster

comboBoxList = ["", "億載金城", "安平樹屋", "林默娘公園", "安平老街", "安平古堡", "東興洋行", "安平開臺天后宮", "安平遊憩碼頭", "台南公園", "花園夜市"
                , "開元寺", "321巷藝術聚落", "祀典武廟", "台灣文學館", "巴克禮公園", "藍曬圖文創園區", "原台南縣知事官邸", "神農街", "台南文創園區", "台南火車站"
                , "大天后宮", "赤崁樓", "林百貨", "延平郡王祠", "海安路藝術街", "成大榕園", "孔廟"]
address = [
    "",
    "台南市安平區光州路二鯤鯓砲臺(億載金城)",
    "台南市安平區古堡街安平樹屋",
    "台南市安平區林默娘公園",
    "台南市安平區延平街安平老街",
    "台南市安平區國勝路安平古堡",

    "台南市安平區安北路233巷東興洋行",
    "台南市安平區國勝路安平開臺天后宮",
    "台南市安平區運河路安平遊憩碼頭",
    "台南市北區公園南路台南公園",
    "台南市北區海安路三段花園夜市 Garden Night Market",

    "台南市北區北園街開元寺",
    "台南市北區公園路321巷321巷 藝術聚落",
    "台南市中西區永福路二段祀典武廟",
    "台南市中西區中正路台灣文學館",
    "台南市東區崇明里巴克禮紀念公園",

    "台南市中西區西門路一段689巷藍晒圖文創園區",
    "台南市東區原台南縣知事官邸和館",
    "台南市中西區神農街",
    "台南市東區北門路二段臺南文化創意產業園區",
    "台南火車站",

    "台南市中西區永福路二段227巷大天后宮",
    "台南市中西區民族路二段赤崁樓",
    "台南市中西區忠義路二段林百貨",
    "台南市中西區開山路延平郡王祠",
    "台南市中西區海安路二段海安路藝術街",

    "台南市東區大學路成大榕園",
    "台南市中西區南門路臺南孔廟",
]

transportation = ['transit', 'driving', 'walking']
trans_ch = ['大眾運輸', '開車', '走路']

class pathThread(QThread):
    path_show = pyqtSignal(str)
    def __init__(self, choose_comboBoxList, choose_path, choose_address):
        QThread.__init__(self)
        self.choose_comboBoxList = choose_comboBoxList
        self.choose_path = choose_path
        self.choose_address = choose_address

    def __del__(self):
        self.wait()
    
    def run(self):
        text = TSP_faster.find_shortest_path_faster(self.choose_comboBoxList, self.choose_path, self.choose_address)
        self.path_show.emit(text)


class updateThread(QThread):
    update_runnning = pyqtSignal(str)
    def __init__(self):
        QThread.__init__(self)

    def __del__(self):
        self.wait()
    
    def run(self):
        for i in range(0, len(transportation)):
            self.update_runnning.emit('更新' + trans_ch[i] + '中')
            google_map.generate_distance_matrix(address, transportation[i])

class TainanTraveling(QtWidgets.QMainWindow, OR_Project_UI.Ui_MainWindow):
    def __init__(self):
        super(self.__class__, self).__init__()
        self.setupUi(self)
        self.comboBox.addItems(comboBoxList)
        for i in range(1, 28):
            self.comboBox.model().item(i).setEnabled(False)

    def add_1(self, state):
        if state == QtCore.Qt.Checked:
            self.comboBox.model().item(1).setEnabled(True)
        else:    
            self.comboBox.model().item(1).setEnabled(False)
            self.comboBox.setCurrentIndex(0)

    def add_2(self, state):
        if state == QtCore.Qt.Checked:
            self.comboBox.model().item(2).setEnabled(True)
        else:    
            self.comboBox.model().item(2).setEnabled(False)
            self.comboBox.setCurrentIndex(0)
    
    def add_3(self, state):
        if state == QtCore.Qt.Checked:
            self.comboBox.model().item(3).setEnabled(True)
        else:    
            self.comboBox.model().item(3).setEnabled(False)
            self.comboBox.setCurrentIndex(0)
    
    def add_4(self, state):
        if state == QtCore.Qt.Checked:
            self.comboBox.model().item(4).setEnabled(True)
        else:    
            self.comboBox.model().item(4).setEnabled(False)
            self.comboBox.setCurrentIndex(0)
    
    def add_5(self, state):
        if state == QtCore.Qt.Checked:
            self.comboBox.model().item(5).setEnabled(True)
        else:    
            self.comboBox.model().item(5).setEnabled(False)
            self.comboBox.setCurrentIndex(0)
    
    def add_6(self, state):
        if state == QtCore.Qt.Checked:
            self.comboBox.model().item(6).setEnabled(True)
        else:    
            self.comboBox.model().item(6).setEnabled(False)
            self.comboBox.setCurrentIndex(0)
    
    def add_7(self, state):
        if state == QtCore.Qt.Checked:
            self.comboBox.model().item(7).setEnabled(True)
        else:    
            self.comboBox.model().item(7).setEnabled(False)
            self.comboBox.setCurrentIndex(0)
    
    def add_8(self, state):
        if state == QtCore.Qt.Checked:
            self.comboBox.model().item(8).setEnabled(True)
        else:    
            self.comboBox.model().item(8).setEnabled(False)
            self.comboBox.setCurrentIndex(0)
    
    def add_9(self, state):
        if state == QtCore.Qt.Checked:
            self.comboBox.model().item(9).setEnabled(True)
        else:    
            self.comboBox.model().item(9).setEnabled(False)
            self.comboBox.setCurrentIndex(0)
    
    def add_10(self, state):
        if state == QtCore.Qt.Checked:
            self.comboBox.model().item(10).setEnabled(True)
        else:    
            self.comboBox.model().item(10).setEnabled(False)
            self.comboBox.setCurrentIndex(0)
    
    def add_11(self, state):
        if state == QtCore.Qt.Checked:
            self.comboBox.model().item(11).setEnabled(True)
        else:    
            self.comboBox.model().item(11).setEnabled(False)
            self.comboBox.setCurrentIndex(0)

    def add_12(self, state):
        if state == QtCore.Qt.Checked:
            self.comboBox.model().item(12).setEnabled(True)
        else:    
            self.comboBox.model().item(12).setEnabled(False)
            self.comboBox.setCurrentIndex(0)
    
    def add_13(self, state):
        if state == QtCore.Qt.Checked:
            self.comboBox.model().item(13).setEnabled(True)
        else:    
            self.comboBox.model().item(13).setEnabled(False)
            self.comboBox.setCurrentIndex(0)
    
    def add_14(self, state):
        if state == QtCore.Qt.Checked:
            self.comboBox.model().item(14).setEnabled(True)
        else:    
            self.comboBox.model().item(14).setEnabled(False)
            self.comboBox.setCurrentIndex(0)
    
    def add_15(self, state):
        if state == QtCore.Qt.Checked:
            self.comboBox.model().item(15).setEnabled(True)
        else:    
            self.comboBox.model().item(15).setEnabled(False)
            self.comboBox.setCurrentIndex(0)
    
    def add_16(self, state):
        if state == QtCore.Qt.Checked:
            self.comboBox.model().item(16).setEnabled(True)
        else:    
            self.comboBox.model().item(16).setEnabled(False)
            self.comboBox.setCurrentIndex(0)
    
    def add_17(self, state):
        if state == QtCore.Qt.Checked:
            self.comboBox.model().item(17).setEnabled(True)
        else:    
            self.comboBox.model().item(17).setEnabled(False)
            self.comboBox.setCurrentIndex(0)
    
    def add_18(self, state):
        if state == QtCore.Qt.Checked:
            self.comboBox.model().item(18).setEnabled(True)
        else:    
            self.comboBox.model().item(18).setEnabled(False)
            self.comboBox.setCurrentIndex(0)

    def add_19(self, state):
        if state == QtCore.Qt.Checked:
            self.comboBox.model().item(19).setEnabled(True)
        else:    
            self.comboBox.model().item(19).setEnabled(False)
            self.comboBox.setCurrentIndex(0)
    
    def add_20(self, state):
        if state == QtCore.Qt.Checked:
            self.comboBox.model().item(20).setEnabled(True)
        else:
            self.comboBox.model().item(20).setEnabled(False)
            self.comboBox.setCurrentIndex(0)

    def add_21(self, state):
        if state == QtCore.Qt.Checked:
            self.comboBox.model().item(21).setEnabled(True)
        else:
            self.comboBox.model().item(21).setEnabled(False)
            self.comboBox.setCurrentIndex(0)

    def add_22(self, state):
        if state == QtCore.Qt.Checked:
            self.comboBox.model().item(22).setEnabled(True)
        else:
            self.comboBox.model().item(22).setEnabled(False)
            self.comboBox.setCurrentIndex(0)

    def add_23(self, state):
        if state == QtCore.Qt.Checked:
            self.comboBox.model().item(23).setEnabled(True)
        else:
            self.comboBox.model().item(23).setEnabled(False)
            self.comboBox.setCurrentIndex(0)

    def add_24(self, state):
        if state == QtCore.Qt.Checked:
            self.comboBox.model().item(24).setEnabled(True)
        else:
            self.comboBox.model().item(24).setEnabled(False)
            self.comboBox.setCurrentIndex(0)

    def add_25(self, state):
        if state == QtCore.Qt.Checked:
            self.comboBox.model().item(25).setEnabled(True)
        else:
            self.comboBox.model().item(25).setEnabled(False)
            self.comboBox.setCurrentIndex(0)

    def add_26(self, state):
        if state == QtCore.Qt.Checked:
            self.comboBox.model().item(26).setEnabled(True)
        else:
            self.comboBox.model().item(26).setEnabled(False)
            self.comboBox.setCurrentIndex(0)

    def add_27(self, state):
        if state == QtCore.Qt.Checked:
            self.comboBox.model().item(27).setEnabled(True)
        else:
            self.comboBox.model().item(27).setEnabled(False)
            self.comboBox.setCurrentIndex(0)

    def all_button_push(self):
        for i in range(1, 28):
            self.comboBox.model().item(i).setEnabled(True)
            self.checkBox.setCheckState(QtCore.Qt.Checked)
            self.checkBox_2.setCheckState(QtCore.Qt.Checked)
            self.checkBox_3.setCheckState(QtCore.Qt.Checked)
            self.checkBox_4.setCheckState(QtCore.Qt.Checked)
            self.checkBox_5.setCheckState(QtCore.Qt.Checked)
            self.checkBox_6.setCheckState(QtCore.Qt.Checked)
            self.checkBox_7.setCheckState(QtCore.Qt.Checked)
            self.checkBox_8.setCheckState(QtCore.Qt.Checked)
            self.checkBox_9.setCheckState(QtCore.Qt.Checked)
            self.checkBox_10.setCheckState(QtCore.Qt.Checked)
            self.checkBox_11.setCheckState(QtCore.Qt.Checked)
            self.checkBox_12.setCheckState(QtCore.Qt.Checked)
            self.checkBox_13.setCheckState(QtCore.Qt.Checked)
            self.checkBox_14.setCheckState(QtCore.Qt.Checked)
            self.checkBox_15.setCheckState(QtCore.Qt.Checked)
            self.checkBox_16.setCheckState(QtCore.Qt.Checked)
            self.checkBox_17.setCheckState(QtCore.Qt.Checked)
            self.checkBox_18.setCheckState(QtCore.Qt.Checked)
            self.checkBox_19.setCheckState(QtCore.Qt.Checked)
            self.checkBox_20.setCheckState(QtCore.Qt.Checked)
            self.checkBox_21.setCheckState(QtCore.Qt.Checked)
            self.checkBox_22.setCheckState(QtCore.Qt.Checked)
            self.checkBox_23.setCheckState(QtCore.Qt.Checked)
            self.checkBox_24.setCheckState(QtCore.Qt.Checked)
            self.checkBox_25.setCheckState(QtCore.Qt.Checked)
            self.checkBox_26.setCheckState(QtCore.Qt.Checked)
            self.checkBox_27.setCheckState(QtCore.Qt.Checked)


    def all_not_button_push(self):
        for i in range(1, 28):
            self.comboBox.model().item(i).setEnabled(False)
            self.checkBox.setCheckState(QtCore.Qt.Unchecked)
            self.checkBox_2.setCheckState(QtCore.Qt.Unchecked)
            self.checkBox_3.setCheckState(QtCore.Qt.Unchecked)
            self.checkBox_4.setCheckState(QtCore.Qt.Unchecked)
            self.checkBox_5.setCheckState(QtCore.Qt.Unchecked)
            self.checkBox_6.setCheckState(QtCore.Qt.Unchecked)
            self.checkBox_7.setCheckState(QtCore.Qt.Unchecked)
            self.checkBox_8.setCheckState(QtCore.Qt.Unchecked)
            self.checkBox_9.setCheckState(QtCore.Qt.Unchecked)
            self.checkBox_10.setCheckState(QtCore.Qt.Unchecked)
            self.checkBox_11.setCheckState(QtCore.Qt.Unchecked)
            self.checkBox_12.setCheckState(QtCore.Qt.Unchecked)
            self.checkBox_13.setCheckState(QtCore.Qt.Unchecked)
            self.checkBox_14.setCheckState(QtCore.Qt.Unchecked)
            self.checkBox_15.setCheckState(QtCore.Qt.Unchecked)
            self.checkBox_16.setCheckState(QtCore.Qt.Unchecked)
            self.checkBox_17.setCheckState(QtCore.Qt.Unchecked)
            self.checkBox_18.setCheckState(QtCore.Qt.Unchecked)
            self.checkBox_19.setCheckState(QtCore.Qt.Unchecked)
            self.checkBox_20.setCheckState(QtCore.Qt.Unchecked)
            self.checkBox_21.setCheckState(QtCore.Qt.Unchecked)
            self.checkBox_22.setCheckState(QtCore.Qt.Unchecked)
            self.checkBox_23.setCheckState(QtCore.Qt.Unchecked)
            self.checkBox_24.setCheckState(QtCore.Qt.Unchecked)
            self.checkBox_25.setCheckState(QtCore.Qt.Unchecked)
            self.checkBox_26.setCheckState(QtCore.Qt.Unchecked)
            self.checkBox_27.setCheckState(QtCore.Qt.Unchecked)
    def path_button_push(self):
        choose_comboBoxList = []
        choose_address = []
        head = None
        trans = None
        if self.checkBox.isChecked():
            choose_comboBoxList += [comboBoxList[0+1]]
            choose_address += [address[0+1]]
        if self.checkBox_2.isChecked():
            choose_comboBoxList += [comboBoxList[1+1]]
            choose_address += [address[1+1]]
        if self.checkBox_3.isChecked():
            choose_comboBoxList += [comboBoxList[2+1]]
            choose_address += [address[2+1]]
        if self.checkBox_4.isChecked():
            choose_comboBoxList += [comboBoxList[3+1]]
            choose_address += [address[3+1]]
        if self.checkBox_5.isChecked():
            choose_comboBoxList += [comboBoxList[4+1]]
            choose_address += [address[4+1]]
        if self.checkBox_6.isChecked():
            choose_comboBoxList += [comboBoxList[5+1]]
            choose_address += [address[5+1]]
        if self.checkBox_7.isChecked():
            choose_comboBoxList += [comboBoxList[6+1]]
            choose_address += [address[6+1]]
        if self.checkBox_8.isChecked():
            choose_comboBoxList += [comboBoxList[7+1]]
            choose_address += [address[7+1]]
        if self.checkBox_9.isChecked():
            choose_comboBoxList += [comboBoxList[8+1]]
            choose_address += [address[8+1]]
        if self.checkBox_10.isChecked():
            choose_comboBoxList += [comboBoxList[9+1]]
            choose_address += [address[9+1]]
        if self.checkBox_11.isChecked():
            choose_comboBoxList += [comboBoxList[10+1]]
            choose_address += [address[10+1]]
        if self.checkBox_12.isChecked():
            choose_comboBoxList += [comboBoxList[11+1]]
            choose_address += [address[11+1]]
        if self.checkBox_13.isChecked():
            choose_comboBoxList += [comboBoxList[12+1]]
            choose_address += [address[12+1]]
        if self.checkBox_14.isChecked():
            choose_comboBoxList += [comboBoxList[13+1]]
            choose_address += [address[13+1]]
        if self.checkBox_15.isChecked():
            choose_comboBoxList += [comboBoxList[14+1]]
            choose_address += [address[14+1]]
        if self.checkBox_16.isChecked():
            choose_comboBoxList += [comboBoxList[15+1]]
            choose_address += [address[15+1]]
        if self.checkBox_17.isChecked():
            choose_comboBoxList += [comboBoxList[16+1]]
            choose_address += [address[16+1]]
        if self.checkBox_18.isChecked():
            choose_comboBoxList += [comboBoxList[17+1]]
            choose_address += [address[17+1]]
        if self.checkBox_19.isChecked():
            choose_comboBoxList += [comboBoxList[18+1]]
            choose_address += [address[18+1]]
        if self.checkBox_20.isChecked():
            choose_comboBoxList += [comboBoxList[19+1]]
            choose_address += [address[19+1]]
        if self.checkBox_21.isChecked():
            choose_comboBoxList += [comboBoxList[20+1]]
            choose_address += [address[20+1]]
        if self.checkBox_22.isChecked():
            choose_comboBoxList += [comboBoxList[21+1]]
            choose_address += [address[21+1]]
        if self.checkBox_23.isChecked():
            choose_comboBoxList += [comboBoxList[22+1]]
            choose_address += [address[22+1]]
        if self.checkBox_24.isChecked():
            choose_comboBoxList += [comboBoxList[23+1]]
            choose_address += [address[23+1]]
        if self.checkBox_25.isChecked():
            choose_comboBoxList += [comboBoxList[24+1]]
            choose_address += [address[24+1]]
        if self.checkBox_26.isChecked():
            choose_comboBoxList += [comboBoxList[25+1]]
            choose_address += [address[25+1]]
        if self.checkBox_27.isChecked():
            choose_comboBoxList += [comboBoxList[26+1]]
            choose_address += [address[26+1]]

        if self.comboBox.currentIndex() != 0 and len(choose_comboBoxList) > 1:
            self.label_5.setText("搜尋路徑...")
            head = comboBoxList[self.comboBox.currentIndex()]
            trans = transportation[self.comboBox_2.currentIndex()]
            print("path push button and ready to compute")
            self.pathPushButton.setEnabled(False)
            self.updatePushButton.setEnabled(False)
            head_address = choose_address[choose_comboBoxList.index(head)]
            choose_address.remove(head_address)
            choose_address = [head_address] + choose_address
            choose_comboBoxList.remove(head)
            choose_comboBoxList = [head] + choose_comboBoxList
            all_path = []
            if trans == 'transit':
                all_path = transit_value.all_to_all_distance
            elif trans == 'driving':
                all_path = driving_value.all_to_all_distance
            elif trans == 'walking':
                all_path = walking_value.all_to_all_distance
            choose_path = []
            for i in range(0, len(choose_comboBoxList)):
                temp = []
                for j in range(0, len(choose_comboBoxList)):
                    temp += [all_path[comboBoxList.index(choose_comboBoxList[i])-1][comboBoxList.index(choose_comboBoxList[j])-1]]
                choose_path += [temp]    
            self.path_thread = pathThread(choose_comboBoxList, choose_path, choose_address)
            self.path_thread.path_show.connect(self.path_show)
            self.path_thread.finished.connect(self.path_done)
            self.path_thread.start()
        else:
            print("path push button but not ready")
            self.label_5.setText("資料不足")

    def path_show(self, text):
        self.textEdit.setText(text)

    def path_done(self):
        self.pathPushButton.setEnabled(True)
        self.updatePushButton.setEnabled(True)
        self.label_5.setText("搜尋完畢！")

    def update_button_push(self):
        self.label_5.setText("更新中...")
        self.pathPushButton.setEnabled(False)
        self.updatePushButton.setEnabled(False)
        print('updating the data')
        self.update_thread = updateThread()
        self.update_thread.update_runnning.connect(self.update_runnning)
        self.update_thread.finished.connect(self.update_done)
        self.update_thread.start()

    
    def update_runnning(self, text):
        self.label_5.setText(text)

    def update_done(self):
        self.label_5.setText("更新完畢！")
        self.pathPushButton.setEnabled(True)
        self.updatePushButton.setEnabled(True)
        print('data updated')

def main():
    app = QtWidgets.QApplication(sys.argv)
    form = TainanTraveling()
    form.show()
    app.exec_()

if __name__ == '__main__':
    main()