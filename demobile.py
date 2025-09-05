
"""
from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.label import Label
from kivy.uix.button import Button

class MyLayout(BoxLayout):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self.orientation = 'horizontal'

        self.label = Label(text="Halo dunia!")
        self.add_widget(self.label)

        self.button = Button(text="Klik aku!")
        self.button.bind(on_press=self.on_button_click)
        self.add_widget(self.button)

    def on_button_click(self, instance):
        self.label.text = "Tombol diklik!"

class MyApp(App):
    def build(self):
        return MyLayout()

if __name__ == "__main__":
    MyApp().run()
"""
from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.label import Label
from kivy.uix.textinput import TextInput
from kivy.uix.button import Button


class CoolingEfficiencyApp(App):
    def build(self):
        self.layout = BoxLayout(orientation='vertical', padding=10, spacing=10)

        self.label1 = Label(text='Masukkan suhu air masuk (°C):')
        self.input1 = TextInput(multiline=False, input_filter='float')
        self.layout.add_widget(self.label1)
        self.layout.add_widget(self.input1)

        self.label2 = Label(text='Masukkan suhu air keluar (°C):')
        self.input2 = TextInput(multiline=False, input_filter='float')
        self.layout.add_widget(self.label2)
        self.layout.add_widget(self.input2)

        self.label3 = Label(text='Masukkan suhu wet bulb (°C):')
        self.input3 = TextInput(multiline=False, input_filter='float')
        self.layout.add_widget(self.label3)
        self.layout.add_widget(self.input3)

        self.result = Label(text='Efisiensi akan ditampilkan di sini.')
        self.layout.add_widget(self.result)
        

        self.button = Button(text='Hitung Efisiensi')
        self.button.bind(on_press=self.calculate_efficiency)
        self.layout.add_widget(self.button)
        self.layout.add_widget

        return self.layout

    def calculate_efficiency(self, instance):
        try:
            t_in = float(self.input1.text)
            t_out = float(self.input2.text)
            t_wetbulb = float(self.input3.text)
            efficiency = ((t_in - t_out) / (t_in - t_wetbulb)) * 100
            self.result.text = f"Efisiensi: {efficiency:.2f}%"
            if (efficiency>100) or (efficiency<0):
                self.result.text = f"Efisiensi: {efficiency:.2f}% (diluar nalar)"
        except Exception as e:
            self.result.text = f"Input tidak valid: {e}"

if __name__ == '__main__':
    CoolingEfficiencyApp().run()
