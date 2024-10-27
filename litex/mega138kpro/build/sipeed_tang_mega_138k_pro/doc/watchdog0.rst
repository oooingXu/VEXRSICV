WATCHDOG0
=========

Register Listing for WATCHDOG0
------------------------------

+----------------------------------------------------+------------------------------------------+
| Register                                           | Address                                  |
+====================================================+==========================================+
| :ref:`WATCHDOG0_CONTROL <WATCHDOG0_CONTROL>`       | :ref:`0xf0004000 <WATCHDOG0_CONTROL>`    |
+----------------------------------------------------+------------------------------------------+
| :ref:`WATCHDOG0_CYCLES <WATCHDOG0_CYCLES>`         | :ref:`0xf0004004 <WATCHDOG0_CYCLES>`     |
+----------------------------------------------------+------------------------------------------+
| :ref:`WATCHDOG0_REMAINING <WATCHDOG0_REMAINING>`   | :ref:`0xf0004008 <WATCHDOG0_REMAINING>`  |
+----------------------------------------------------+------------------------------------------+
| :ref:`WATCHDOG0_EV_STATUS <WATCHDOG0_EV_STATUS>`   | :ref:`0xf000400c <WATCHDOG0_EV_STATUS>`  |
+----------------------------------------------------+------------------------------------------+
| :ref:`WATCHDOG0_EV_PENDING <WATCHDOG0_EV_PENDING>` | :ref:`0xf0004010 <WATCHDOG0_EV_PENDING>` |
+----------------------------------------------------+------------------------------------------+
| :ref:`WATCHDOG0_EV_ENABLE <WATCHDOG0_EV_ENABLE>`   | :ref:`0xf0004014 <WATCHDOG0_EV_ENABLE>`  |
+----------------------------------------------------+------------------------------------------+

WATCHDOG0_CONTROL
^^^^^^^^^^^^^^^^^

`Address: 0xf0004000 + 0x0 = 0xf0004000`

    Watchdog Control.

    .. wavedrom::
        :caption: WATCHDOG0_CONTROL

        {
            "reg": [
                {"name": "feed",  "type": 4, "bits": 1},
                {"bits": 7},
                {"name": "enable",  "bits": 1},
                {"bits": 7},
                {"name": "reset",  "bits": 1},
                {"bits": 7},
                {"name": "pause_halted",  "bits": 1},
                {"bits": 7}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 4 }, "options": {"hspace": 400, "bits": 32, "lanes": 4}
        }


+-------+--------------+--------------------------------------+
| Field | Name         | Description                          |
+=======+==============+======================================+
| [0]   | FEED         | Watchdog feed (Write ``1`` to feed). |
+-------+--------------+--------------------------------------+
| [8]   | ENABLE       | Watchdog enable.                     |
+-------+--------------+--------------------------------------+
| [16]  | RESET        | Reset SoC when watchdog times out.   |
+-------+--------------+--------------------------------------+
| [24]  | PAUSE_HALTED | Pause watchdog when CPU is halted.   |
+-------+--------------+--------------------------------------+

WATCHDOG0_CYCLES
^^^^^^^^^^^^^^^^

`Address: 0xf0004000 + 0x4 = 0xf0004004`

    Watchdog cycles until timeout.

    .. wavedrom::
        :caption: WATCHDOG0_CYCLES

        {
            "reg": [
                {"name": "cycles[31:0]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


WATCHDOG0_REMAINING
^^^^^^^^^^^^^^^^^^^

`Address: 0xf0004000 + 0x8 = 0xf0004008`

    Watchdog cycles remaining until timeout.

    .. wavedrom::
        :caption: WATCHDOG0_REMAINING

        {
            "reg": [
                {"name": "remaining[31:0]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


WATCHDOG0_EV_STATUS
^^^^^^^^^^^^^^^^^^^

`Address: 0xf0004000 + 0xc = 0xf000400c`

    This register contains the current raw level of the wdt event trigger.  Writes
    to this register have no effect.

    .. wavedrom::
        :caption: WATCHDOG0_EV_STATUS

        {
            "reg": [
                {"name": "wdt",  "bits": 1},
                {"bits": 31}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 4 }, "options": {"hspace": 400, "bits": 32, "lanes": 4}
        }


+-------+------+----------------------------+
| Field | Name | Description                |
+=======+======+============================+
| [0]   | WDT  | Level of the ``wdt`` event |
+-------+------+----------------------------+

WATCHDOG0_EV_PENDING
^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0004000 + 0x10 = 0xf0004010`

    When a  wdt event occurs, the corresponding bit will be set in this register.
    To clear the Event, set the corresponding bit in this register.

    .. wavedrom::
        :caption: WATCHDOG0_EV_PENDING

        {
            "reg": [
                {"name": "wdt",  "bits": 1},
                {"bits": 31}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 4 }, "options": {"hspace": 400, "bits": 32, "lanes": 4}
        }


+-------+------+-------------------------------------------------------------------------------+
| Field | Name | Description                                                                   |
+=======+======+===============================================================================+
| [0]   | WDT  | `1` if a `wdt` event occurred. This Event is triggered on a **falling** edge. |
+-------+------+-------------------------------------------------------------------------------+

WATCHDOG0_EV_ENABLE
^^^^^^^^^^^^^^^^^^^

`Address: 0xf0004000 + 0x14 = 0xf0004014`

    This register enables the corresponding wdt events.  Write a ``0`` to this
    register to disable individual events.

    .. wavedrom::
        :caption: WATCHDOG0_EV_ENABLE

        {
            "reg": [
                {"name": "wdt",  "bits": 1},
                {"bits": 31}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 4 }, "options": {"hspace": 400, "bits": 32, "lanes": 4}
        }


+-------+------+-------------------------------------------+
| Field | Name | Description                               |
+=======+======+===========================================+
| [0]   | WDT  | Write a ``1`` to enable the ``wdt`` Event |
+-------+------+-------------------------------------------+

