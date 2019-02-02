## HOW-TO: Share button maps

Steps on how to get your controller configuration included in the next Kodi release.

### 1. Creating button maps

Button maps can be generated from within the GUI. See the following wiki articles:

* **[HOW-TO: Configure controllers](https://kodi.wiki/view/HOW-TO:Configure_controllers)**
* **[HOW-TO: Map multiple controllers](https://kodi.wiki/view/HOW-TO:Map_multiple_controllers)**

These map GUI elements to XML files. The XML files can be found in [userdata](https://kodi.wiki/view/Userdata):

`userdata/addon_data/peripheral.joystick/resources/buttonmaps/xml/<joystick driver>/`

### 2. Clone this repo

`git clone https://github.com/xbmc/peripheral.joystick.git`

### 3. Add your button map

Copy the XML file created by the GUI (or by hand) to the folder:

`peripheral.joystick/resources/buttonmaps/xml/<joystick driver>/`

You can see the existing button maps here:

* [XML button maps](https://github.com/xbmc/peripheral.joystick/tree/master/peripheral.joystick/resources/buttonmaps/xml)

### 4. Create the pull request

Commit the file and send the pull request to the peripheral.joystick repo.
