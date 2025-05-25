# University of Melbourne E-Waste Sorting Hub
*Team A2*
<br>

A modular, scalable prototype for promoting responsible e-waste disposal across University of Melbourne campuses. Developed in response to stakeholder feedback, this project aims to simplify the sorting of batteries and e-waste, increase user awareness, and support the university’s **Sustainability Plan 2030** goals for circularity.

## Project Goals
- Increase clarity and accessibility around e-waste disposal.
- Reduce contamination and misuse of e-waste bins.
- Separate battery and general e-waste for safe disposal.
- Align with UoM’s Sustainability Plan 2030: circularity, tracking, and environmental justice.
- Create a **modular**, **low-cost**, and **scalable** solution for deployment across faculties.

## Features
- **Card Activation**: RFID/button-based interaction to begin the sorting process.
- **LCD Instructions**: Real-time visual guidance for users.
- **Battery vs E-Waste Detection**: Selection via button or image classification (future).
- **Conveyor Belt Sorting**: Servo-controlled mechanism separates items.
- **QR Signage & Feedback**: Large visual cues and QR codes linking to instructions.
- **Expandable AI**: Prepared for integration with TensorFlow/YOLOv8 computer vision models for automated classification.



### Schematics 

| **Schematics Page 1** | **Schematics Page 2** |
|-----------------------------------------|------------------------------------------------------|
| <img src="images/schematics_1.png" width="750" alt="Schematics 1" /> | <img src="images/schematics_2.png" width="750" alt="Schematics 2" /> |

<br>



### Prototype (Digital User Testing Feedback)

| **Original Prototype for User Testing** | **Updated Prototype Based on User Testing Feedback** |
|-----------------------------------------|------------------------------------------------------|
| <img src="images/prototype_testing_1.png" width="750" alt="Original Prototype" /> | <img src="images/prototype_testing.png" width="750" alt="Updated Prototype" /> |

<br>


### Prototype (CAD Testing Feedback)

| **Updated visuals based on User Testing** |
|-----------------------------------------|
| <img src="images/user_testing_feedback.png" width="750" alt="Original Prototype" /> |

<br>



## User Testing Insights
| Stakeholder        | Insight                                                                 |
|--------------------|-------------------------------------------------------------------------|
| TCS & Sustainability | Need for lithium battery handling clarity; e-waste approx. 0.2m³/year. |
| Jobelle (Tech Staff)| Existing collection systems unclear; risks of battery misplacement.     |
| PhD Students/Staff  | Instructions on bins unclear, hard to book disposal support.            |
| Graduate Researcher & Staff La Trobe University M.Corbel Staff  | LCD screen is needed for informing users.       |

### Changes from Feedback:
- Improved **signage** and added **images**.
- Enhanced **screen messaging with LCD**.
- Designed **rear-access bins** for easy collection (TCP feedback).

## Stakeholders
- **Internal**: Campus Assist, Sustainability Team, TCS, Staff and Students
- **External**: Envirostream, Ecobatt, Cleanaway, Staff Latrobe University

## Contents
| File | Description |
|------|-------------|
| `a2_arduino_code_lo_fi.ino` | Arduino sketch controlling sorting logic |
| `tinkercad_schematics.pdf` | Circuit design exported from Tinkercad |
| `tinkercad_1.png` - `tinkercad_4.png` | Views of circuit from Tinkercad |
| `images/01.jpg` - `images/18.jpg` | Photos from prototype, poster, signage |
| `a2_lo_fi_prototype_view_1.png`, `view_2.png` | Lo-fi prototype snapshots |
| `E-waste bin poster.pptx` | Printable awareness poster design |

## Hardware (Lo-Fi Prototype)
- Arduino Uno
- Servo motor (conveyor sorting)
- LCD 16x2 display (parallel)
- Button inputs (card, battery type)
- Power supply & breadboard setup
- Optional: RFID scanner for card-based access

[View Tinkercad Circuit](https://www.tinkercad.com/things/1ucuSc4Ial4/editel?sharecode=mLrZAbDzcxXoekwXmUjWTCLxmmftjxwgGwGp0jVNXQU)

### Presentation – University of Melbourne (UoM)

| **Prototype Step 1** <br> Tap card to begin | **Prototype Step 2** <br> Select size: small | **Prototype Step 3** <br> Battery loaded | **Prototype Step 4** <br> Battery check |
|--------------------------------------------|---------------------------------------------|------------------------------------------|------------------------------------------|
| <img src="images/01.jpg" width="300" alt="Step 1" /> | <img src="images/02.jpg" width="300" alt="Step 2" /> | <img src="images/03.jpg" width="300" alt="Step 3" /> | <img src="images/04.jpg" width="300" alt="Step 4" /> |

| **Prototype Step 5** <br> Battery check = yes | **Prototype Step 6** <br> Sorting | **Prototype Step 7** <br> USB loaded | **Prototype Step 8** <br> Battery check = no |
|----------------------------------------------|----------------------------------|-------------------------------------|--------------------------------------------|
| <img src="images/05.jpg" width="300" alt="Step 5" /> | <img src="images/06.jpg" width="300" alt="Step 6" /> | <img src="images/07.jpg" width="300" alt="Step 7" /> | <img src="images/08.jpg" width="300" alt="Step 8" /> |

| **Prototype Step 9** <br> Sorting | **Prototype Step 10** <br> Completed: Points received | **Prototype Step 11** <br> Select size: medium | **Prototype Step 12** <br> Locker opened |
|----------------------------------|-------------------------------------------------------|--------------------------------------------|------------------------------------------|
| <img src="images/09.jpg" width="300" alt="Step 9" /> | <img src="images/10.jpg" width="300" alt="Step 10" /> | <img src="images/11.jpg" width="300" alt="Step 11" /> | <img src="images/12.jpg" width="300" alt="Step 12" /> |

| **Prototype Step 13** <br> Locker closed | **Prototype Step 14** <br> Completed: Points received | **Prototype Step 15** <br> Select size: large | **Prototype Step 16** <br> ServiceNow request |
|------------------------------------------|------------------------------------------------------|---------------------------------------------|--------------------------------------------|
| <img src="images/13.jpg" width="300" alt="Step 13" /> | <img src="images/14.jpg" width="300" alt="Step 14" /> | <img src="images/15.jpg" width="300" alt="Step 15" /> | <img src="images/16.jpg" width="300" alt="Step 16" /> |

| **Prototype Step 17** <br> Service receipt | **Prototype Step 18** <br> Completed: Points received |  |  |
|-------------------------------------------|------------------------------------------------------|---------------------------------------------|--------------------------------------------|
| <img src="images/17.jpg" width="300" alt="Step 17" /> | <img src="images/18.jpg" width="300" alt="Step 18" /> |  |  |

<br>


<br>

## Design Overview
![Prototype View](images/a2_lo_fi_prototype_view_1.png)
![Prototype View](images/a2_lo_fi_prototype_view_2.png)

- Card interaction simulates secure user input.
- Battery and e-waste differentiated using user-selected logic (future: camera).
- Conveyor moves item to correct bin using servo.
- Guidance shown via LCD and printed signage.
- Modular enclosure for scale-up.

## Next Proposed Phase: AI
- Trained using Kaggle image dataset for battery/e-waste classification.
- Model deployment using YOLOv8 or TechnoLynx micro-models.
- Potential for gamified user feedback via dashboard.

## Next Steps
- Finalize detection method (camera or button logic).
- Pilot system in one faculty space.
- Test camera-based classification model.
- Improve enclosure for long-term deployment.
- Final deployment guide for university-wide scale-up.


## Collection POD / Hub Evaluation Table

| **Evaluation Criteria**               | **Weighted** | **Reason**                                                                                                                                               |
|--------------------------------------|--------------|----------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Energy Efficiency**                | 4            | Uses sensors and servo motors efficiently; minimal power use. Manual handling greatly reduced.                                                           |
| **Cost implications**                | 3            | Upfront cost for tech and infrastructure; long-term savings from reduced manual labour and contamination.                                               |
| **Innovation**                       | 5            | Introduces autonomous sorting, gamification, QR-code integration, and real-time bin tracking.                                                           |
| **Awareness (easily noticeable)**    | 4            | Highly visible portal with clear signage, screen prompts, and QR codes; improves awareness campus-wide.                                                 |
| **Ease of implementation**           | 3            | Moderate complexity due to sensors, card system, and ServiceNow integration. Feasible with planning.                                                    |
| **Impact / effectiveness**           | 4            | Encourages high engagement via confetti, rewards, and feedback; sorts waste accurately and securely.                                                    |
| **Effectiveness of External Partnerships** | 3      | Partners with external battery collectors; potential to expand to other recyclers or circular providers.                                                |
| **Impact of Accessibility**          | 4            | Accessible interface, card scanner, guided steps, visual cues, and inclusive user flow.                                                                 |
| **Potential for circularity**        | 4            | Tracks reuse/donation, avoids contamination, supports data collection and transparency.                                                                 |
| **Maintenance and Support**          | 3            | Needs servicing for bins and tech; sensor alerts help minimize downtime.                                                                                |
| **Time commitment (training)**       | 4            | Minimal training required; system guides users with step-by-step instructions and automation.                                                           |

---

| **Weighted Total (+)** | **Weighted Total (-)** | **Final Score** |
|------------------------|------------------------|-----------------|
| 41                     | 0                      | **41**          |


## Future
| Theme | Sample Question | Suggested Answer |
|-------|------------------|------------------|
| Feasibility | Is large-scale rollout realistic? | Yes, due to modularity, low-cost electronics, and adaptable design. |
| Testing | What did you learn from user testing? | Signage improved clarity. Rear-access bin and LCD guidance well-received. |
| Collaboration | How did your team work together? | Regular team voting, feedback on OneDrive, prototyping at Telstra Creator Space. |
| Unknowns | Why did you prototype sorting? | Sorting was the most critical failure point. Focused on battery/e-waste decision logic. |

## Links
- [Miro Board (Project Planning)](https://miro.com/app/board/uXjVIR7Ld8A=/)
- [GitHub Repository](https://github.com/leakydishes/e-waste-uom-hub/)
- [Tinkercad Circuit](https://www.tinkercad.com/things/1ucuSc4Ial4/editel?sharecode=mLrZAbDzcxXoekwXmUjWTCLxmmftjxwgGwGp0jVNXQU)

## License
This project is for educational and research purposes under the University of Melbourne.
