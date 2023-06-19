import math

def calculate_frequency(octave, note_index, root_frequency):
    frequency_ratio = pow(2.0, 1.0 / 12.0)  # Frequency ratio between adjacent notes
    relative_index = octave * 7 + note_index
    frequency = root_frequency * pow(frequency_ratio, relative_index)
    return frequency

root_frequency = float(input("Enter the root frequency of the starting note: "))

notes = ["C", "D", "E", "F", "G", "A", "B"]
octave_range = 8

for octave in range(2, octave_range + 3):
    for note_index in range(7):
        frequency = calculate_frequency(octave, note_index, root_frequency)
        print(f"{notes[note_index]}{octave}: {frequency} Hz")