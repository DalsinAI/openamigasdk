import importlib.util
from pathlib import Path
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[2]
SPEC = importlib.util.spec_from_file_location("gather", ROOT / "tools/gather.py")
M = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(M)


class GatherReceiptTests(unittest.TestCase):
    def test_missing_or_changed_receipt_is_rejected(self):
        with tempfile.TemporaryDirectory() as d:
            root = Path(d)
            part = dict(name="fixture", files={"source.h": "header.h"})
            manifest = dict(parts=[part])
            with self.assertRaisesRegex(ValueError, "incomplete"):
                M.offline_check(manifest, root)
            (root / "header.h").write_bytes(b"header")
            part["sha256"] = {"header.h": M.hashlib.sha256(b"header").hexdigest()}
            M.offline_check(manifest, root)
            (root / "header.h").write_bytes(b"modified")
            with self.assertRaisesRegex(ValueError, "changed"):
                M.offline_check(manifest, root)

    def test_generated_fd_also_requires_a_receipt(self):
        part = dict(files={"a.sfd": "SFD/a.sfd", "b.sfd": "OpenNDK/SFD/b.sfd"})
        self.assertEqual(M.output_paths(part), {"SFD/a.sfd", "FD/a.fd", "OpenNDK/SFD/b.sfd"})
