from xml.dom.minidom import parse


class Recording:
    def __init__(self, faculty, department, full_name, academic_title, academic_degree, work_experience):
        self.faculty = faculty
        self.department = department
        self.full_name = full_name
        self.academic_title = academic_title
        self.academic_degree = academic_degree
        self.work_experience = work_experience


class RecordingsManager:
    def __init__(self):  # creating list of recordings
        self.recordings = []

    def add_recording(self, recording):  # adding recording to list
        self.recordings.append(recording)

    def del_recording(self, recording_ind):  # deleting recording from list by index
        self.recordings.pop(recording_ind)

    def clear_recordings(self):  # clearing the whole list
        self.recordings = []

    def upload_list(self, path):
        dom = parse(path)
        recordings = dom.getElementsByTagName("recording")

        for recording in recordings:
            faculty = recording.getElementsByTagName("faculty")[0].childNodes[0].data
            department = recording.getElementsByTagName("department")[0].childNodes[0].data
            full_name = recording.getElementsByTagName("full_name")[0].childNodes[0].data
            academic_title = recording.getElementsByTagName("academic_title")[0].childNodes[0].data
            academic_degree = recording.getElementsByTagName("academic_degree")[0].childNodes[0].data
            work_experience = recording.getElementsByTagName("work_experience")[0].childNodes[0].data

            self.add_recording(Recording(faculty, department, full_name, academic_title, academic_degree,
                                         work_experience))

Table = RecordingsManager()

Table.add_recording("")