SDRAM
=====

Register Listing for SDRAM
--------------------------

+--------------------------------------------------------------------+--------------------------------------------------+
| Register                                                           | Address                                          |
+====================================================================+==================================================+
| :ref:`SDRAM_DFII_CONTROL <SDRAM_DFII_CONTROL>`                     | :ref:`0xf0002000 <SDRAM_DFII_CONTROL>`           |
+--------------------------------------------------------------------+--------------------------------------------------+
| :ref:`SDRAM_DFII_PI0_COMMAND <SDRAM_DFII_PI0_COMMAND>`             | :ref:`0xf0002004 <SDRAM_DFII_PI0_COMMAND>`       |
+--------------------------------------------------------------------+--------------------------------------------------+
| :ref:`SDRAM_DFII_PI0_COMMAND_ISSUE <SDRAM_DFII_PI0_COMMAND_ISSUE>` | :ref:`0xf0002008 <SDRAM_DFII_PI0_COMMAND_ISSUE>` |
+--------------------------------------------------------------------+--------------------------------------------------+
| :ref:`SDRAM_DFII_PI0_ADDRESS <SDRAM_DFII_PI0_ADDRESS>`             | :ref:`0xf000200c <SDRAM_DFII_PI0_ADDRESS>`       |
+--------------------------------------------------------------------+--------------------------------------------------+
| :ref:`SDRAM_DFII_PI0_BADDRESS <SDRAM_DFII_PI0_BADDRESS>`           | :ref:`0xf0002010 <SDRAM_DFII_PI0_BADDRESS>`      |
+--------------------------------------------------------------------+--------------------------------------------------+
| :ref:`SDRAM_DFII_PI0_WRDATA3 <SDRAM_DFII_PI0_WRDATA3>`             | :ref:`0xf0002014 <SDRAM_DFII_PI0_WRDATA3>`       |
+--------------------------------------------------------------------+--------------------------------------------------+
| :ref:`SDRAM_DFII_PI0_WRDATA2 <SDRAM_DFII_PI0_WRDATA2>`             | :ref:`0xf0002018 <SDRAM_DFII_PI0_WRDATA2>`       |
+--------------------------------------------------------------------+--------------------------------------------------+
| :ref:`SDRAM_DFII_PI0_WRDATA1 <SDRAM_DFII_PI0_WRDATA1>`             | :ref:`0xf000201c <SDRAM_DFII_PI0_WRDATA1>`       |
+--------------------------------------------------------------------+--------------------------------------------------+
| :ref:`SDRAM_DFII_PI0_WRDATA0 <SDRAM_DFII_PI0_WRDATA0>`             | :ref:`0xf0002020 <SDRAM_DFII_PI0_WRDATA0>`       |
+--------------------------------------------------------------------+--------------------------------------------------+
| :ref:`SDRAM_DFII_PI0_RDDATA3 <SDRAM_DFII_PI0_RDDATA3>`             | :ref:`0xf0002024 <SDRAM_DFII_PI0_RDDATA3>`       |
+--------------------------------------------------------------------+--------------------------------------------------+
| :ref:`SDRAM_DFII_PI0_RDDATA2 <SDRAM_DFII_PI0_RDDATA2>`             | :ref:`0xf0002028 <SDRAM_DFII_PI0_RDDATA2>`       |
+--------------------------------------------------------------------+--------------------------------------------------+
| :ref:`SDRAM_DFII_PI0_RDDATA1 <SDRAM_DFII_PI0_RDDATA1>`             | :ref:`0xf000202c <SDRAM_DFII_PI0_RDDATA1>`       |
+--------------------------------------------------------------------+--------------------------------------------------+
| :ref:`SDRAM_DFII_PI0_RDDATA0 <SDRAM_DFII_PI0_RDDATA0>`             | :ref:`0xf0002030 <SDRAM_DFII_PI0_RDDATA0>`       |
+--------------------------------------------------------------------+--------------------------------------------------+
| :ref:`SDRAM_DFII_PI1_COMMAND <SDRAM_DFII_PI1_COMMAND>`             | :ref:`0xf0002034 <SDRAM_DFII_PI1_COMMAND>`       |
+--------------------------------------------------------------------+--------------------------------------------------+
| :ref:`SDRAM_DFII_PI1_COMMAND_ISSUE <SDRAM_DFII_PI1_COMMAND_ISSUE>` | :ref:`0xf0002038 <SDRAM_DFII_PI1_COMMAND_ISSUE>` |
+--------------------------------------------------------------------+--------------------------------------------------+
| :ref:`SDRAM_DFII_PI1_ADDRESS <SDRAM_DFII_PI1_ADDRESS>`             | :ref:`0xf000203c <SDRAM_DFII_PI1_ADDRESS>`       |
+--------------------------------------------------------------------+--------------------------------------------------+
| :ref:`SDRAM_DFII_PI1_BADDRESS <SDRAM_DFII_PI1_BADDRESS>`           | :ref:`0xf0002040 <SDRAM_DFII_PI1_BADDRESS>`      |
+--------------------------------------------------------------------+--------------------------------------------------+
| :ref:`SDRAM_DFII_PI1_WRDATA3 <SDRAM_DFII_PI1_WRDATA3>`             | :ref:`0xf0002044 <SDRAM_DFII_PI1_WRDATA3>`       |
+--------------------------------------------------------------------+--------------------------------------------------+
| :ref:`SDRAM_DFII_PI1_WRDATA2 <SDRAM_DFII_PI1_WRDATA2>`             | :ref:`0xf0002048 <SDRAM_DFII_PI1_WRDATA2>`       |
+--------------------------------------------------------------------+--------------------------------------------------+
| :ref:`SDRAM_DFII_PI1_WRDATA1 <SDRAM_DFII_PI1_WRDATA1>`             | :ref:`0xf000204c <SDRAM_DFII_PI1_WRDATA1>`       |
+--------------------------------------------------------------------+--------------------------------------------------+
| :ref:`SDRAM_DFII_PI1_WRDATA0 <SDRAM_DFII_PI1_WRDATA0>`             | :ref:`0xf0002050 <SDRAM_DFII_PI1_WRDATA0>`       |
+--------------------------------------------------------------------+--------------------------------------------------+
| :ref:`SDRAM_DFII_PI1_RDDATA3 <SDRAM_DFII_PI1_RDDATA3>`             | :ref:`0xf0002054 <SDRAM_DFII_PI1_RDDATA3>`       |
+--------------------------------------------------------------------+--------------------------------------------------+
| :ref:`SDRAM_DFII_PI1_RDDATA2 <SDRAM_DFII_PI1_RDDATA2>`             | :ref:`0xf0002058 <SDRAM_DFII_PI1_RDDATA2>`       |
+--------------------------------------------------------------------+--------------------------------------------------+
| :ref:`SDRAM_DFII_PI1_RDDATA1 <SDRAM_DFII_PI1_RDDATA1>`             | :ref:`0xf000205c <SDRAM_DFII_PI1_RDDATA1>`       |
+--------------------------------------------------------------------+--------------------------------------------------+
| :ref:`SDRAM_DFII_PI1_RDDATA0 <SDRAM_DFII_PI1_RDDATA0>`             | :ref:`0xf0002060 <SDRAM_DFII_PI1_RDDATA0>`       |
+--------------------------------------------------------------------+--------------------------------------------------+

SDRAM_DFII_CONTROL
^^^^^^^^^^^^^^^^^^

`Address: 0xf0002000 + 0x0 = 0xf0002000`

    Control DFI signals common to all phases

    .. wavedrom::
        :caption: SDRAM_DFII_CONTROL

        {
            "reg": [
                {"name": "sel",  "attr": '1', "bits": 1},
                {"name": "cke",  "bits": 1},
                {"name": "odt",  "bits": 1},
                {"name": "reset_n",  "bits": 1},
                {"bits": 28}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 4 }, "options": {"hspace": 400, "bits": 32, "lanes": 4}
        }


+-------+---------+-------------------------------------------+
| Field | Name    | Description                               |
+=======+=========+===========================================+
| [0]   | SEL     |                                           |
|       |         |                                           |
|       |         | +---------+-----------------------------+ |
|       |         | | Value   | Description                 | |
|       |         | +=========+=============================+ |
|       |         | | ``0b0`` | Software (CPU) control.     | |
|       |         | +---------+-----------------------------+ |
|       |         | | ``0b1`` | Hardware control (default). | |
|       |         | +---------+-----------------------------+ |
+-------+---------+-------------------------------------------+
| [1]   | CKE     | DFI clock enable bus                      |
+-------+---------+-------------------------------------------+
| [2]   | ODT     | DFI on-die termination bus                |
+-------+---------+-------------------------------------------+
| [3]   | RESET_N | DFI clock reset bus                       |
+-------+---------+-------------------------------------------+

SDRAM_DFII_PI0_COMMAND
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002000 + 0x4 = 0xf0002004`

    Control DFI signals on a single phase

    .. wavedrom::
        :caption: SDRAM_DFII_PI0_COMMAND

        {
            "reg": [
                {"name": "cs",  "bits": 1},
                {"name": "we",  "bits": 1},
                {"name": "cas",  "bits": 1},
                {"name": "ras",  "bits": 1},
                {"name": "wren",  "bits": 1},
                {"name": "rden",  "bits": 1},
                {"name": "cs_top",  "bits": 1},
                {"name": "cs_bottom",  "bits": 1},
                {"bits": 24}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 4 }, "options": {"hspace": 400, "bits": 32, "lanes": 4}
        }


+-------+-----------+------------------------------------------+
| Field | Name      | Description                              |
+=======+===========+==========================================+
| [0]   | CS        | DFI chip select bus                      |
+-------+-----------+------------------------------------------+
| [1]   | WE        | DFI write enable bus                     |
+-------+-----------+------------------------------------------+
| [2]   | CAS       | DFI column address strobe bus            |
+-------+-----------+------------------------------------------+
| [3]   | RAS       | DFI row address strobe bus               |
+-------+-----------+------------------------------------------+
| [4]   | WREN      | DFI write data enable bus                |
+-------+-----------+------------------------------------------+
| [5]   | RDEN      | DFI read data enable bus                 |
+-------+-----------+------------------------------------------+
| [6]   | CS_TOP    | DFI chip select bus for top half only    |
+-------+-----------+------------------------------------------+
| [7]   | CS_BOTTOM | DFI chip select bus for bottom half only |
+-------+-----------+------------------------------------------+

SDRAM_DFII_PI0_COMMAND_ISSUE
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002000 + 0x8 = 0xf0002008`


    .. wavedrom::
        :caption: SDRAM_DFII_PI0_COMMAND_ISSUE

        {
            "reg": [
                {"name": "dfii_pi0_command_issue", "bits": 1},
                {"bits": 31},
            ], "config": {"hspace": 400, "bits": 32, "lanes": 4 }, "options": {"hspace": 400, "bits": 32, "lanes": 4}
        }


SDRAM_DFII_PI0_ADDRESS
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002000 + 0xc = 0xf000200c`

    DFI address bus

    .. wavedrom::
        :caption: SDRAM_DFII_PI0_ADDRESS

        {
            "reg": [
                {"name": "dfii_pi0_address[14:0]", "bits": 15},
                {"bits": 17},
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


SDRAM_DFII_PI0_BADDRESS
^^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002000 + 0x10 = 0xf0002010`

    DFI bank address bus

    .. wavedrom::
        :caption: SDRAM_DFII_PI0_BADDRESS

        {
            "reg": [
                {"name": "dfii_pi0_baddress[2:0]", "bits": 3},
                {"bits": 29},
            ], "config": {"hspace": 400, "bits": 32, "lanes": 4 }, "options": {"hspace": 400, "bits": 32, "lanes": 4}
        }


SDRAM_DFII_PI0_WRDATA3
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002000 + 0x14 = 0xf0002014`

    Bits 96-127 of `SDRAM_DFII_PI0_WRDATA`. DFI write data bus

    .. wavedrom::
        :caption: SDRAM_DFII_PI0_WRDATA3

        {
            "reg": [
                {"name": "dfii_pi0_wrdata[127:96]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


SDRAM_DFII_PI0_WRDATA2
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002000 + 0x18 = 0xf0002018`

    Bits 64-95 of `SDRAM_DFII_PI0_WRDATA`.

    .. wavedrom::
        :caption: SDRAM_DFII_PI0_WRDATA2

        {
            "reg": [
                {"name": "dfii_pi0_wrdata[95:64]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


SDRAM_DFII_PI0_WRDATA1
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002000 + 0x1c = 0xf000201c`

    Bits 32-63 of `SDRAM_DFII_PI0_WRDATA`.

    .. wavedrom::
        :caption: SDRAM_DFII_PI0_WRDATA1

        {
            "reg": [
                {"name": "dfii_pi0_wrdata[63:32]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


SDRAM_DFII_PI0_WRDATA0
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002000 + 0x20 = 0xf0002020`

    Bits 0-31 of `SDRAM_DFII_PI0_WRDATA`.

    .. wavedrom::
        :caption: SDRAM_DFII_PI0_WRDATA0

        {
            "reg": [
                {"name": "dfii_pi0_wrdata[31:0]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


SDRAM_DFII_PI0_RDDATA3
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002000 + 0x24 = 0xf0002024`

    Bits 96-127 of `SDRAM_DFII_PI0_RDDATA`. DFI read data bus

    .. wavedrom::
        :caption: SDRAM_DFII_PI0_RDDATA3

        {
            "reg": [
                {"name": "dfii_pi0_rddata[127:96]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


SDRAM_DFII_PI0_RDDATA2
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002000 + 0x28 = 0xf0002028`

    Bits 64-95 of `SDRAM_DFII_PI0_RDDATA`.

    .. wavedrom::
        :caption: SDRAM_DFII_PI0_RDDATA2

        {
            "reg": [
                {"name": "dfii_pi0_rddata[95:64]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


SDRAM_DFII_PI0_RDDATA1
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002000 + 0x2c = 0xf000202c`

    Bits 32-63 of `SDRAM_DFII_PI0_RDDATA`.

    .. wavedrom::
        :caption: SDRAM_DFII_PI0_RDDATA1

        {
            "reg": [
                {"name": "dfii_pi0_rddata[63:32]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


SDRAM_DFII_PI0_RDDATA0
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002000 + 0x30 = 0xf0002030`

    Bits 0-31 of `SDRAM_DFII_PI0_RDDATA`.

    .. wavedrom::
        :caption: SDRAM_DFII_PI0_RDDATA0

        {
            "reg": [
                {"name": "dfii_pi0_rddata[31:0]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


SDRAM_DFII_PI1_COMMAND
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002000 + 0x34 = 0xf0002034`

    Control DFI signals on a single phase

    .. wavedrom::
        :caption: SDRAM_DFII_PI1_COMMAND

        {
            "reg": [
                {"name": "cs",  "bits": 1},
                {"name": "we",  "bits": 1},
                {"name": "cas",  "bits": 1},
                {"name": "ras",  "bits": 1},
                {"name": "wren",  "bits": 1},
                {"name": "rden",  "bits": 1},
                {"name": "cs_top",  "bits": 1},
                {"name": "cs_bottom",  "bits": 1},
                {"bits": 24}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 4 }, "options": {"hspace": 400, "bits": 32, "lanes": 4}
        }


+-------+-----------+------------------------------------------+
| Field | Name      | Description                              |
+=======+===========+==========================================+
| [0]   | CS        | DFI chip select bus                      |
+-------+-----------+------------------------------------------+
| [1]   | WE        | DFI write enable bus                     |
+-------+-----------+------------------------------------------+
| [2]   | CAS       | DFI column address strobe bus            |
+-------+-----------+------------------------------------------+
| [3]   | RAS       | DFI row address strobe bus               |
+-------+-----------+------------------------------------------+
| [4]   | WREN      | DFI write data enable bus                |
+-------+-----------+------------------------------------------+
| [5]   | RDEN      | DFI read data enable bus                 |
+-------+-----------+------------------------------------------+
| [6]   | CS_TOP    | DFI chip select bus for top half only    |
+-------+-----------+------------------------------------------+
| [7]   | CS_BOTTOM | DFI chip select bus for bottom half only |
+-------+-----------+------------------------------------------+

SDRAM_DFII_PI1_COMMAND_ISSUE
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002000 + 0x38 = 0xf0002038`


    .. wavedrom::
        :caption: SDRAM_DFII_PI1_COMMAND_ISSUE

        {
            "reg": [
                {"name": "dfii_pi1_command_issue", "bits": 1},
                {"bits": 31},
            ], "config": {"hspace": 400, "bits": 32, "lanes": 4 }, "options": {"hspace": 400, "bits": 32, "lanes": 4}
        }


SDRAM_DFII_PI1_ADDRESS
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002000 + 0x3c = 0xf000203c`

    DFI address bus

    .. wavedrom::
        :caption: SDRAM_DFII_PI1_ADDRESS

        {
            "reg": [
                {"name": "dfii_pi1_address[14:0]", "bits": 15},
                {"bits": 17},
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


SDRAM_DFII_PI1_BADDRESS
^^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002000 + 0x40 = 0xf0002040`

    DFI bank address bus

    .. wavedrom::
        :caption: SDRAM_DFII_PI1_BADDRESS

        {
            "reg": [
                {"name": "dfii_pi1_baddress[2:0]", "bits": 3},
                {"bits": 29},
            ], "config": {"hspace": 400, "bits": 32, "lanes": 4 }, "options": {"hspace": 400, "bits": 32, "lanes": 4}
        }


SDRAM_DFII_PI1_WRDATA3
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002000 + 0x44 = 0xf0002044`

    Bits 96-127 of `SDRAM_DFII_PI1_WRDATA`. DFI write data bus

    .. wavedrom::
        :caption: SDRAM_DFII_PI1_WRDATA3

        {
            "reg": [
                {"name": "dfii_pi1_wrdata[127:96]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


SDRAM_DFII_PI1_WRDATA2
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002000 + 0x48 = 0xf0002048`

    Bits 64-95 of `SDRAM_DFII_PI1_WRDATA`.

    .. wavedrom::
        :caption: SDRAM_DFII_PI1_WRDATA2

        {
            "reg": [
                {"name": "dfii_pi1_wrdata[95:64]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


SDRAM_DFII_PI1_WRDATA1
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002000 + 0x4c = 0xf000204c`

    Bits 32-63 of `SDRAM_DFII_PI1_WRDATA`.

    .. wavedrom::
        :caption: SDRAM_DFII_PI1_WRDATA1

        {
            "reg": [
                {"name": "dfii_pi1_wrdata[63:32]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


SDRAM_DFII_PI1_WRDATA0
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002000 + 0x50 = 0xf0002050`

    Bits 0-31 of `SDRAM_DFII_PI1_WRDATA`.

    .. wavedrom::
        :caption: SDRAM_DFII_PI1_WRDATA0

        {
            "reg": [
                {"name": "dfii_pi1_wrdata[31:0]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


SDRAM_DFII_PI1_RDDATA3
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002000 + 0x54 = 0xf0002054`

    Bits 96-127 of `SDRAM_DFII_PI1_RDDATA`. DFI read data bus

    .. wavedrom::
        :caption: SDRAM_DFII_PI1_RDDATA3

        {
            "reg": [
                {"name": "dfii_pi1_rddata[127:96]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


SDRAM_DFII_PI1_RDDATA2
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002000 + 0x58 = 0xf0002058`

    Bits 64-95 of `SDRAM_DFII_PI1_RDDATA`.

    .. wavedrom::
        :caption: SDRAM_DFII_PI1_RDDATA2

        {
            "reg": [
                {"name": "dfii_pi1_rddata[95:64]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


SDRAM_DFII_PI1_RDDATA1
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002000 + 0x5c = 0xf000205c`

    Bits 32-63 of `SDRAM_DFII_PI1_RDDATA`.

    .. wavedrom::
        :caption: SDRAM_DFII_PI1_RDDATA1

        {
            "reg": [
                {"name": "dfii_pi1_rddata[63:32]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


SDRAM_DFII_PI1_RDDATA0
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002000 + 0x60 = 0xf0002060`

    Bits 0-31 of `SDRAM_DFII_PI1_RDDATA`.

    .. wavedrom::
        :caption: SDRAM_DFII_PI1_RDDATA0

        {
            "reg": [
                {"name": "dfii_pi1_rddata[31:0]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


