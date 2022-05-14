package es.protector;

import org.bukkit.ChatColor;
import org.bukkit.Location;
import org.bukkit.Material;
import org.bukkit.enchantments.Enchantment;
import org.bukkit.inventory.ItemFlag;
import org.bukkit.inventory.ItemStack;
import org.bukkit.inventory.meta.ItemMeta;

import java.util.ArrayList;
import java.util.List;

public class Util {
    public static String color(String texto) {
        return ChatColor.translateAlternateColorCodes('&', texto);
    }

    public static ItemStack createItem(int materialID, int amount, String displayName, String[] loreString) {
        ItemStack item;
        List<String> lore = new ArrayList();

        item = new ItemStack(Material.getMaterial(materialID), amount);

        ItemMeta meta = item.getItemMeta();
        meta.setDisplayName(Util.color(displayName));

        for(String s : loreString) {
            lore.add(Util.color(s));
        }
        meta.setLore(lore);
        item.setItemMeta(meta);

        return item;
    }
    public static ItemStack createItem(int materialID, int byteID, int amount, String displayName, String[] loreString) {
        ItemStack item;
        List<String> lore = new ArrayList();

        item = new ItemStack(Material.getMaterial(materialID), amount, (short) byteID);

        ItemMeta meta = item.getItemMeta();
        meta.setDisplayName(Util.color(displayName));

        for(String s : loreString) {
            lore.add(Util.color(s));
        }
        meta.setLore(lore);
        item.setItemMeta(meta);

        return item;
    }
    public static ItemStack createItem(String materialNAME, int amount, String displayName, String[] loreString) {
        ItemStack item;
        List<String> lore = new ArrayList();

        item = new ItemStack(Material.getMaterial(materialNAME.toUpperCase()), amount);

        ItemMeta meta = item.getItemMeta();
        meta.setDisplayName(Util.color(displayName));

        for(String s : loreString) {
            lore.add(Util.color(s));
        }
        meta.setLore(lore);
        item.setItemMeta(meta);

        return item;
    }
    public static ItemStack createItem(String materialNAME, int byteID, int amount, String displayName, String[] loreString) {
        ItemStack item;
        List<String> lore = new ArrayList();

        item = new ItemStack(Material.valueOf(materialNAME.toLowerCase()), amount, (short) byteID);

        ItemMeta meta = item.getItemMeta();
        meta.setDisplayName(Util.color(displayName));

        for(String s : loreString) {
            lore.add(Util.color(s));
        }
        meta.setLore(lore);
        item.setItemMeta(meta);

        return item;
    }
    public static ItemStack enchant(ItemStack item, String enchant, int level) {
        ItemStack toreturn = new ItemStack(item);
        ItemMeta meta = toreturn.getItemMeta();
        meta.addEnchant(Enchantment.getByName(enchant), level, true);
        toreturn.setItemMeta(meta);
        return toreturn;
    }
    public static ItemStack enchant(ItemStack item, int enchant, int level) {
        ItemStack toreturn = new ItemStack(item);
        ItemMeta meta = toreturn.getItemMeta();
        meta.addEnchant(Enchantment.getById(enchant), level, true);
        toreturn.setItemMeta(meta);
        return toreturn;
    }
    public static ItemStack hideEnchant(ItemStack item) {
        ItemStack toreturn = new ItemStack(item);
        ItemMeta meta = toreturn.getItemMeta();
        meta.addItemFlags(ItemFlag.HIDE_ENCHANTS);
        toreturn.setItemMeta(meta);
        return toreturn;
    }
    public static ItemStack hideUnbreak(ItemStack item) {
        ItemStack toreturn = new ItemStack(item);
        ItemMeta meta = toreturn.getItemMeta();
        meta.addItemFlags(ItemFlag.HIDE_UNBREAKABLE);
        toreturn.setItemMeta(meta);
        return toreturn;
    }

    public static boolean PlayerIsIn(Location tocheck, Location min, Location max) {
        boolean toreturn = false;

        if(tocheck.getWorld() == min.getWorld() && tocheck.getWorld() == max.getWorld()) {
            if(tocheck.getX() >= min.getX() && tocheck.getX() <= max.getX()) {
                if(tocheck.getY() >= min.getY() && tocheck.getY() <= max.getY()) {
                    if(tocheck.getZ() >= min.getZ() && tocheck.getZ() <= max.getZ()) {
                        toreturn = true;
                    }
                }
            }
        }
        if(tocheck.getX() <= min.getX() && tocheck.getX() >= max.getX()) {
            if(tocheck.getY() <= min.getY() && tocheck.getY() >= max.getY()) {
                if(tocheck.getZ() <= min.getZ() && tocheck.getZ() >= max.getZ()) {
                    toreturn = true;
                }
            }
        }

        return toreturn;
    }
}
